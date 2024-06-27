#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

// Function to delete a node from the binary tree
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("FAILED: node not found\n");
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            printf("SUCCESS: node removed\n");
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            printf("SUCCESS: node removed\n");
            return temp;
        }

        struct Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
