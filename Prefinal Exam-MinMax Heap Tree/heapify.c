#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "heaptree.h"

// Helper function to heapify up for Max Heap
void heapifyUpMax(struct Node* root, struct Node* newNode) {
    if (root == NULL || newNode == root) return;

    struct Node* parent = NULL;
    struct Node* current = root;
    struct Node* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = current;

    // Find parent of newNode
    while (front < rear) {
        current = queue[front++];
        if (current->left == newNode || current->right == newNode) {
            parent = current;
            break;
        }
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }

    if (parent && parent->weight < newNode->weight) {
        char tempWord[4];
        int tempWeight;

        strcpy(tempWord, parent->word);
        tempWeight = parent->weight;

        strcpy(parent->word, newNode->word);
        parent->weight = newNode->weight;

        strcpy(newNode->word, tempWord);
        newNode->weight = tempWeight;

        heapifyUpMax(root, parent);
    }
}

// Helper function to heapify up for Min Heap
void heapifyUpMin(struct Node* root, struct Node* newNode) {
    if (root == NULL || newNode == root) return;

    struct Node* parent = NULL;
    struct Node* current = root;
    struct Node* queue[MAX_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = current;

    // Find parent of newNode
    while (front < rear) {
        current = queue[front++];
        if (current->left == newNode || current->right == newNode) {
            parent = current;
            break;
        }
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }

    if (parent && parent->weight > newNode->weight) {
        char tempWord[4];
        int tempWeight;

        strcpy(tempWord, parent->word);
        tempWeight = parent->weight;

        strcpy(parent->word, newNode->word);
        parent->weight = newNode->weight;

        strcpy(newNode->word, tempWord);
        newNode->weight = tempWeight;

        heapifyUpMin(root, parent);
    }
}

// Helper function to heapify down for Max Heap
void heapifyDownMax(struct Node* root) {
    if (root == NULL) return;

    struct Node* largest = root;
    struct Node* left = root->left;
    struct Node* right = root->right;

    if (left && left->weight > largest->weight) {
        largest = left;
    }
    if (right && right->weight > largest->weight) {
        largest = right;
    }
    if (largest != root) {
        char tempWord[4];
        int tempWeight;

        strcpy(tempWord, root->word);
        tempWeight = root->weight;

        strcpy(root->word, largest->word);
        root->weight = largest->weight;

        strcpy(largest->word, tempWord);
        largest->weight = tempWeight;

        heapifyDownMax(largest);
    }
}

// Helper function to heapify down for Min Heap
void heapifyDownMin(struct Node* root) {
    if (root == NULL) return;

    struct Node* smallest = root;
    struct Node* left = root->left;
    struct Node* right = root->right;

    if (left && left->weight < smallest->weight) {
        smallest = left;
    }
    if (right && right->weight < smallest->weight) {
        smallest = right;
    }
    if (smallest != root) {
        char tempWord[4];
        int tempWeight;

        strcpy(tempWord, root->word);
        tempWeight = root->weight;

        strcpy(root->word, smallest->word);
        root->weight = smallest->weight;

        strcpy(smallest->word, tempWord);
        smallest->weight = tempWeight;

        heapifyDownMin(smallest);
    }
}
