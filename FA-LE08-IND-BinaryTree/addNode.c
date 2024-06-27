#include <stdio.h> 
#include <stdlib.h>
#include "binarytree.h"

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add a node to the binary tree
void addNode(struct Node** root, int value) {
    struct Node* newNode = createNode(value);
    if (*root == NULL) {
        *root = newNode;
        printf("SUCCESS: node added\n");
        return;
    }

    // Queue for level-order traversal
    struct Node* queue[100]; // Assuming max 100 nodes
    int front = 0, rear = -1;

    queue[++rear] = *root;
    while (front <= rear) {
        struct Node* temp = queue[front++];
        if (temp->left == NULL) {
            temp->left = newNode;
            printf("SUCCESS: node added\n");
            return;
        } else {
            queue[++rear] = temp->left;
        }
        if (temp->right == NULL) {
            temp->right = newNode;
            printf("SUCCESS: node added\n");
            return;
        } else {
            queue[++rear] = temp->right;
        }
    }
}
