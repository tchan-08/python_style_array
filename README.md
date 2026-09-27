# Dynamic Array (C)

A small C implementation of a Python-style dynamic array (list) backed by
`realloc`-based memory management.

## Features

| Function | Description |
|---|---|
| `init(array)` | Initializes an empty array |
| `print(array)` | Prints the array as `[1, 2, 3]` |
| `count(array)` | Returns the number of elements |
| `append(array, item)` | Adds an item to the end |
| `pop(array)` | Removes and returns the last item |
| `insert(array, item, index)` | Inserts an item at a given index |
| `remove_item(array, item)` | Removes the first matching item |
| `reverse(array)` | Reverses the array in place |
| `sort(array)` | Sorts the array in place (bubble sort) |

## Usage

```c
#include "array.h"

int main() {
    struct Array myArray;
    init(&myArray);

    append(&myArray, 5);
    append(&myArray, 2);
    append(&myArray, 9);
    print(&myArray);        // [5, 2, 9]

    insert(&myArray, 1, 0);
    print(&myArray);        // [1, 5, 2, 9]

    sort(&myArray);
    print(&myArray);        // [1, 2, 5, 9]

    remove_item(&myArray, 5);
    print(&myArray);        // [1, 2, 9]

    reverse(&myArray);
    print(&myArray);        // [9, 2, 1]

    int last = pop(&myArray);
    printf("Popped: %d\n", last); // Popped: 1

    printf("Count: %d\n", count(&myArray)); // Count: 2

    return 0;
}
```

## Build

```bash
gcc -o array main.c
./array
```