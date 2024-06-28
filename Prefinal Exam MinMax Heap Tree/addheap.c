#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "heaptree.h"

// Function to insert a new node into the Max Heap
void insertToMaxHeap(struct Node** root, char word[]) {
    struct Node* newNode = createNode(word);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Level-order insertion using a queue
    struct Node* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = *root;

    while (front < rear) {
        struct Node* current = queue[front++];
        if (current->left == NULL) {
            current->left = newNode;
            heapifyUpMax(*root, current->left);
            break;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = newNode;
            heapifyUpMax(*root, current->right);
            break;
        } else {
            queue[rear++] = current->right;
        }
    }
}

// Function to insert a new node into the Min Heap
void insertToMinHeap(struct Node** root, char word[]) {
    struct Node* newNode = createNode(word);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Level-order insertion using a queue
    struct Node* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = *root;

    while (front < rear) {
        struct Node* current = queue[front++];
        if (current->left == NULL) {
            current->left = newNode;
            heapifyUpMin(*root, current->left);
            break;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = newNode;
            heapifyUpMin(*root, current->right);
            break;
        } else {
            queue[rear++] = current->right;
        }
    }
}
