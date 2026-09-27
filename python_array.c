#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
PLAN
- create a python style array
- dynamic memory allocation
- print(), append(), pop(), insert(), remove(), reverse(), sort(), count()
*/

struct Array {
    int *contents;
    int size; 
};

void init(struct Array *array) {
    array->contents = NULL;
    array->size = 0;
}

void print(struct Array *array) {
    if (array->size == 0) {
        printf("[]\n");
        return;
    } 
    printf("[");
    for (int i = 0; i < array->size - 1; i++) {
        printf("%d, ", array->contents[i]);
    }
    printf("%d]\n", array->contents[array->size - 1]);
}

int count(struct Array *array) {
    return array->size;
}

void append(struct Array *array, int item) {
    array->size = array->size + 1;
    array->contents = realloc(array->contents, array->size * sizeof(int));
    array->contents[array->size-1] = item;
}

int pop(struct Array *array) {
    if (array->size <= 0) {
        perror("Cannot pop an empty array.\n");
        return -1;
    }
    int popped = array->contents[array->size-1];
    array->size = array->size - 1;
    array->contents = realloc(array->contents, array->size * sizeof(int));
    return popped;
}

void insert(struct Array *array, int item, int index) {
    if (index > array->size || index < 0) {
        perror("Index out of range.\n");
    } else {
        array->contents = realloc(array->contents, (array->size + 1) * sizeof(int));
        for (int i = array->size; i > index; i--) {
            array->contents[i] = array->contents[i-1];
        } 
        array->contents[index] = item;
        array->size = array->size + 1;
    }
}

void remove_item(struct Array *array, int item) {
    if (array->size == 0) {
        perror("Cannot remove from an empty array.\n");
        return;
    }
    for (int i = 0; i < array->size; i++) {
        if (array->contents[i] == item) {
            for (int j = i + 1; j < array->size; j++) {
                array->contents[j - 1] = array->contents[j];
            }
            array->size = array->size - 1;
            array->contents = realloc(array->contents, array->size * sizeof(int));
            return;
        }
    }
    perror("Item not found.\n");
}

void reverse(struct Array *array) {
    if (array->size <= 1) {
        return;
    }
    for (int i = 0; i < array->size; i++) {
        int temp = array->contents[i];
        int complement = array->size - i-1;
        if (complement == i || i > array->size / 2) {
            return;
        }
        array->contents[i] = array->contents[complement];
        array->contents[complement] = temp;
    }
}

void sort(struct Array *array) {
    for (int i = 0; i < array->size; i++) {
        bool swapped = false;
        for (int j = 0; j < array->size-1; j++) {
            if (array->contents[j+1] < array->contents[j]) {
                int temp = array->contents[j];
                array->contents[j] = array->contents[j+1];
                array->contents[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
    }
}

int main() {
    struct Array myArray;
    init(&myArray);
    return 0;
}