/*
============================================================================
FILE        : delete.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Deletes the node and heapify if imbalanced.
COPYRIGHT   : 4 April 2024
REVISION HISTORY
Date:               By:
revision date
Description:
author         description of the change
revision date
.
.
.
revision date
author         description of the change
author         description of the change
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "addnode.h"
#include "delete.h"
#include "display.h"
#include "heapify.h"
#include "traversals.h"

/*
============================================================================
FUNCTION    : deleteNode
DESCRIPTION : Deletes specified root and heapifies
ARGUMENTS   : struct Node** root - pointer to a pointer root of type struct Node
			int value - value to compare with in tree
dataType variableName - brief description
RETURNS     : int
===========================================================================
*/
// Function to delete a node from the binary search tree
int deleteRoot(struct Node** root) {
    if (*root == NULL) {
        printf("Heap is empty\n");
        return -1;
    }

    int deletedValue = (*root)->data;

    // Find the rightmost node in the last level
    struct Node* lastNode = *root;
    while (lastNode->right) {
        lastNode = lastNode->right;
    }

    printf("\n***********\n");
    printTree((*root), 0);
    printf("Press any key to continue... ");
    getche();
    // Replace the root with the rightmost node
    (*root)->data = lastNode->data;
    printf("\n***********\n");
    printTree((*root), 0);
    printf("Press any key to continue... ");
    getche();
    // Delete the rightmost node
    if (lastNode == *root) {
        free(lastNode);
        *root = NULL;
        return deletedValue;
    }

    struct Node* parentNode = getParentNode(*root, lastNode);
    if (parentNode->right == lastNode) {
        free(parentNode->right);
        parentNode->right = NULL;
    } else {
        free(parentNode->left);
        parentNode->left = NULL;
    }

    // Heapify starting from the root after deleting the node
    heapify(*root);

    return deletedValue;
}

struct Node* getParentNode(struct Node* root, struct Node* child) {
    if (root == NULL || root == child) {
        return NULL;
    }

    if (root->left == child || root->right == child) {
        return root;
    }

    struct Node* leftParent = getParentNode(root->left, child);
    if (leftParent != NULL) {
        return leftParent;
    }

    return getParentNode(root->right, child);
}
