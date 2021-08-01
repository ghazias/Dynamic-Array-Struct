#ifndef DYNAMIC_INT_ARRAY_H_
#define DYNAMIC_INT_ARRAY_H_

#include <stdbool.h>
#include <stddef.h>

struct IntArray {
  int* data; // pointer to array data
  size_t size; // total actual elements
  size_t capacity; // total possible elements
};

// Create an array with the given size. Initialize all elements to 0.
struct IntArray* create_array(void);

// free all associated data. You must free both the IntArray struct, and any
// data you allocated within it. Every malloc() needs a free()
void free_array(struct IntArray* array);

// return true if the array contains a given Element
bool contains(const struct IntArray* array, int elem);

// return largest element in the array
int max_element(const struct IntArray* array);

// return smallest element in the array
int min_element(const struct IntArray* array);

// return true if the two arrays have the same contents
bool equals(const struct IntArray* lhs, const struct IntArray* rhs);

// appends element to end of array if size < capacity, doubles space if not
void append(struct IntArray* array, int element);

// inserts element at passed index
void insert(struct IntArray* array, int element, size_t index);

void for_each(struct IntArray* array, void (*func)(int));

struct IntArray* map(struct IntArray* array, int (*func)(int));

struct IntArray* filter(struct IntArray* array, bool (*func)(int));

int pop(struct IntArray* array);

struct IntArray* duplicate(const struct IntArray* array);

#endif
