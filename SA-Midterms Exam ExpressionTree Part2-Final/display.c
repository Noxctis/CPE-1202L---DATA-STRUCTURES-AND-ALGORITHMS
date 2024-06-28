#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "expressiontree.h"

// Function to perform an inorder traversal of the expression tree
void printInorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}

// Function to print the expression tree
void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    // Increase distance between levels
    space += 10;
    // Process right child first
    printTree(root->right, space);
    // Print current node after space count
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", root->data);
    // Process left child
    printTree(root->left, space);
}
