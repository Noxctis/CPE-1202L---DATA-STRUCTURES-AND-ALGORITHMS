#ifndef HEAPARRAY_H_INCLUDED
#define HEAPARRAY_H_INCLUDED

#define MAX_SIZE 100

// Structure for each node containing a three-character word and its weight
struct Node {
    char word[4];
    int weight;
};

// Function prototypes
void addToMaxHeap(struct Node heap[], int *size, char word[]);
void addToMinHeap(struct Node heap[], int *size, char word[]);
void deleteFromMaxHeap(struct Node heap[], int *size);
void deleteFromMinHeap(struct Node heap[], int *size);
void displayHeap(struct Node heap[], int size, int isMaxHeap, int index, int depth);
int calculateWeight(char word[]);

#endif // HEAPARRAY_H_INCLUDED
