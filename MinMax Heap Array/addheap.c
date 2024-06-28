#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heaparray.h"

// Function to calculate the weight of a word
int calculateWeight(char word[]) {
    int weight = 0;
    for (int i = 0; i < 3; ++i) {
        weight += (word[i] - 'A' + 1);
    }
    return weight;
}


// Function to add a new node to the Max Heap
void addToMaxHeap(struct Node heap[], int *size, char word[]) {
    if (*size == MAX_SIZE) {
        printf("Max Heap is full. Cannot add more nodes.\n");
        return;
    }

    struct Node newNode;
    strcpy(newNode.word, word);
    newNode.weight = calculateWeight(word);

    heap[*size] = newNode;
    *size += 1;

    // Heapify up for Max Heap
    int i = *size - 1;
    while (i > 0 && heap[(i - 1) / 2].weight < heap[i].weight) {
        struct Node temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to add a new node to the Min Heap
void addToMinHeap(struct Node heap[], int *size, char word[]) {
    if (*size == MAX_SIZE) {
        printf("Min Heap is full. Cannot add more nodes.\n");
        return;
    }

    struct Node newNode;
    strcpy(newNode.word, word);
    newNode.weight = calculateWeight(word);

    heap[*size] = newNode;
    *size += 1;

    // Heapify up for Min Heap
    int i = *size - 1;
    while (i > 0 && heap[(i - 1) / 2].weight > heap[i].weight) {
        struct Node temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
