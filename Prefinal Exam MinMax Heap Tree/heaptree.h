#ifndef HEAPTREE_H_INCLUDED
#define HEAPTREE_H_INCLUDED

#define MAX_SIZE 100

// Structure for each node containing a three-character word and its weight
struct Node {
    char word[4];
    int weight;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(char word[]);
void insertToMaxHeap(struct Node** root, char word[]);
void insertToMinHeap(struct Node** root, char word[]);
struct Node* deleteRootMaxHeap(struct Node* root);
struct Node* deleteRootMinHeap(struct Node* root);
void displayHeap(struct Node* root, int depth);
int calculateWeight(char word[]);
void heapifyUpMax(struct Node* root, struct Node* newNode);
void heapifyUpMin(struct Node* root, struct Node* newNode);
void heapifyDownMax(struct Node* root);
void heapifyDownMin(struct Node* root);

#endif // HEAPTREE_H_INCLUDED
