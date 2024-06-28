#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "heaptree.h"

// Function to delete root from Max Heap
struct Node* deleteRootMaxHeap(struct Node* root) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    struct Node* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;

    struct Node* lastNode = NULL;
    struct Node* parent = NULL;
    while (front < rear) {
        lastNode = queue[front++];
        if (lastNode->left) {
            parent = lastNode;
            queue[rear++] = lastNode->left;
        }
        if (lastNode->right) {
            parent = lastNode;
            queue[rear++] = lastNode->right;
        }
    }

    strcpy(root->word, lastNode->word);
    root->weight = lastNode->weight;

    if (parent->left == lastNode) {
        parent->left = NULL;
    } else {
        parent->right = NULL;
    }
    free(lastNode);

    // Heapify down
    heapifyDownMax(root);

    return root;
}

// Function to delete root from Min Heap
struct Node* deleteRootMinHeap(struct Node* root) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    struct Node* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;

    struct Node* lastNode = NULL;
    struct Node* parent = NULL;
    while (front < rear) {
        lastNode = queue[front++];
        if (lastNode->left) {
            parent = lastNode;
            queue[rear++] = lastNode->left;
        }
        if (lastNode->right) {
            parent = lastNode;
            queue[rear++] = lastNode->right;
        }
    }

    strcpy(root->word, lastNode->word);
    root->weight = lastNode->weight;

    if (parent->left == lastNode) {
        parent->left = NULL;
    } else {
        parent->right = NULL;
    }
    free(lastNode);

    // Heapify down
    heapifyDownMin(root);

    return root;
}
