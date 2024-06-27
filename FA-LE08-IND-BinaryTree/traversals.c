#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

// Function to perform breadth-first traversal
void breadthFirstTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[100]; // Assuming a maximum of 100 nodes for simplicity
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// Function to traverse the binary tree in Inorder
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in Preorder
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to traverse the binary tree in Postorder
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to print the text-based representation of the binary tree
void printTree(struct Node* root, int level) {
    if (root == NULL)
        return;

    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", root->data);

    printTree(root->left, level + 1);
}

#define MOVE_UP(x) printf("\e[%dA", x)
#define MOVE_DOWN(x) printf("\e[%dB", x)

void treeMode(struct Node* root){
    if (!root) return;

    int maxDepth = treeDepth(root, 1);

    for (int i = 0; i < maxDepth; i++) printf("\n");
    MOVE_UP(maxDepth);
    treeDisplay(root, 1);
    MOVE_DOWN(maxDepth);
    printf("\n");

}

int treeDepth(struct Node* root, int depth){
    if (!root) return depth - 1;

    int dLeft = treeDepth(root->left, depth + 1);
    int dRight = treeDepth(root->right, depth + 1);

    return (dLeft > dRight) ? dLeft : dRight;
}

void treeDisplay(struct Node* root, int depth){
    if (!root) return;

    treeDisplay(root->left, depth + 1);
    MOVE_DOWN(depth);
    printf("[%3d]", root->data, depth);
    MOVE_UP(depth);
    treeDisplay(root->right, depth + 1);
}
