#include "intarray.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static void print_value(int value) {
    printf("%d\n", value);
}

static int square(int value) {
    return value * value;
}

static bool keep_it_50(int value) {
    if (value >= 50) {
        return true;
    }
    
    return false;
}

int main() {
    struct IntArray* a1 = create_array();
    assert(a1->size == 0);
    assert(a1->capacity == 2);

    printf("a1 size: %zu\n", a1->size);
    printf("a1 capacity: %zu\n", a1->capacity);

    append(a1, 12);
    append(a1, 20);
    append(a1, 50);

    printf("a1 size: %zu\n", a1->size);
    printf("a1 capacity: %zu\n", a1->capacity);

    printf("max element: %d\n", max_element(a1));
    printf("min element: %d\n", min_element(a1));

    printf("contains 20?: %d\n", contains(a1, 20));
    printf("pop: %d\n", pop(a1));

    append(a1, 45);

    struct IntArray* dupArr = duplicate(a1);

    printf("dupArr max element: %d\n", max_element(dupArr));
    printf("dupArr min element: %d\n", min_element(dupArr));

    //printf("Pop: %d\n", pop(dupArr));

    append(dupArr, 84);
    append(dupArr, 63);
    append(dupArr, 99);

    printf("dupArr size: %zu\n", dupArr->size);
    printf("dupArr capacity: %zu\n", dupArr->capacity);
    printf("pop: %d\n", pop(dupArr));
    
    printf("\n");

    insert(dupArr, 8, 2);
    assert(dupArr->data[2] == 8);
    
    for_each(dupArr, print_value);
    printf("\n");
    // The different code styles are filthy, I know
    struct IntArray* mapped_array = map(dupArr, square);
    for_each(mapped_array, print_value);
    printf("\n");
    struct IntArray* greater_than_fifty = filter(dupArr, keep_it_50);
    for_each(greater_than_fifty, print_value);
    
    free_array(a1);
    a1 = NULL;

    free_array(dupArr);
    dupArr = NULL;
}
