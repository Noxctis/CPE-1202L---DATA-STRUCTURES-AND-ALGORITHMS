#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heaparray.h"

// Function to delete root from Max Heap
void deleteFromMaxHeap(struct Node heap[], int *size) {
    // Replace root with last node
    heap[0] = heap[*size - 1];
    *size -= 1;

    // Heapify down for Max Heap
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int largest = current;

        if (left < *size && heap[left].weight > heap[largest].weight) {
            largest = left;
        }

        if (right < *size && heap[right].weight > heap[largest].weight) {
            largest = right;
        }

        if (largest != current) {
            struct Node temp = heap[current];
            heap[current] = heap[largest];
            heap[largest] = temp;
            current = largest;
        } else {
            break;
        }
    }
}

// Function to delete root from Min Heap
void deleteFromMinHeap(struct Node heap[], int *size) {
    // Replace root with last node
    heap[0] = heap[*size - 1];
    *size -= 1;

    // Heapify down for Min Heap
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;

        if (left < *size && heap[left].weight < heap[smallest].weight) {
            smallest = left;
        }

        if (right < *size && heap[right].weight < heap[smallest].weight) {
            smallest = right;
        }

        if (smallest != current) {
            struct Node temp = heap[current];
            heap[current] = heap[smallest];
            heap[smallest] = temp;
            current = smallest;
        } else {
            break;
        }
    }
}
