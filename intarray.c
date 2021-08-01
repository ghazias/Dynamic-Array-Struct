#include "intarray.h"
#include <stdlib.h>

static void grow_array(struct IntArray* array) {
    array->capacity *= 2;
    array->data = realloc(array->data, array->capacity * sizeof *array->data);
}

struct IntArray* create_array(void) {
    struct IntArray* my_array = malloc(sizeof *my_array); // create space for array struct
    my_array->size = 0; // set initial real occupancy to 0
    my_array->capacity = 2; // set current max occupancy to 2
    my_array->data = calloc(my_array->capacity, sizeof *my_array->data); // allocate capacity * size of my_array type bytes for array data

    return my_array;
}

void free_array(struct IntArray* array) {
    free(array->data);
    free(array);
}

void for_each(struct IntArray* array, void (*func)(int)) {
    for (size_t i = 0; i < array->size; i++) {
        func(array->data[i]);
    }
}

struct IntArray* map(struct IntArray* array, int (*func)(int)) {
    struct IntArray* mapped_array = create_array();
    for(size_t i = 0; i <array->size; i++) {
        append(mapped_array, func(array->data[i]));
    }
    
    return mapped_array;
}

struct IntArray* filter(struct IntArray* array, bool (*func)(int)) {
    struct IntArray* filtered_array = create_array();
    for(size_t i = 0; i < array->size; i++) {
        if(func(array->data[i])) {
            append(filtered_array, array->data[i]);
        }
    }
    
    return filtered_array;
}

bool contains(const struct IntArray* array, int elem) {
    for (size_t i = 0; i < array->size; i++) {
        if (array->data[i] == elem) {
            return true;
        }
    }
    return false;
}

int max_element(const struct IntArray* array) {
    int max = array->data[0];
    for (size_t i = 0; i < array->size; i++) {
        if (array->data[i] > max) {
            max = array->data[i];
        }
    }
    return max;
}

int min_element(const struct IntArray* array) {
    int min = array->data[0];
    for (size_t i = 0; i < array->size; i++) {
        if (array->data[i] < min) {
            min = array->data[i];
        }
    }
    return min;
}

bool equals(const struct IntArray* lhs, const struct IntArray* rhs) {
    if (lhs->size != rhs->size) {
        return false;
    }
    for (size_t i = 0; i < lhs->size; i++) {
        if (lhs->data[i] != rhs->data[i]) {
            return false;
        }
    }
    return true;
}

void append(struct IntArray* array, int element) {
    if (array->size < array->capacity) { // if current occupancy < capacity
        array->data[array->size++] = element; // add element to current max index and increment afterwards
    } else { // size will be greater than capacity, so grow the array
        array->capacity *= 2; // double array capacity
        array->data = realloc(array->data, array->capacity * sizeof *array->data); // reallocate array with greater capacity
        array->data[array->size++] = element; // add new element after growth
    }
}

void insert(struct IntArray* array, int element, size_t index) {
    if (array->size == array->capacity) {
       grow_array(array);
    }
    for (size_t i = array->size - 1; i > index; i--) {
            array->data[i] = array->data[i - 1];
        }
    array->size++;
    array->data[index] = element; // finally, insert the desired value
}

int pop(struct IntArray* array) {
    return array->data[--array->size];
}

struct IntArray* duplicate(const struct IntArray* array) {
    struct IntArray* new_array = malloc(sizeof *new_array); // malloc new array struct
    new_array->size = array->size; // set size
    new_array->capacity = array->capacity; // set capacity
    new_array->data = calloc(new_array->capacity, sizeof *new_array->data); // malloc space for values

    for (size_t i = 0; i < array->size; i++) {
        new_array->data[i] = array->data[i];
    }
    return new_array;
}
