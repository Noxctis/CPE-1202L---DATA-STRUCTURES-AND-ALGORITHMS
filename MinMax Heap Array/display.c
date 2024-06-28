#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heaparray.h"

// Function to display heap as a tree
void displayHeap(struct Node heap[], int size, int isMaxHeap, int index, int depth) {
    if (index < size) {
        displayHeap(heap, size, isMaxHeap, 2 * index + 2, depth + 1); // right child
        for (int i = 0; i < depth; i++) {
            printf("   ");
        }
        printf("%s %02d\n", heap[index].word, heap[index].weight);
        displayHeap(heap, size, isMaxHeap, 2 * index + 1, depth + 1); // left child
    }
}
