/*
============================================================================
FILE        : heapify.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Heapify Tree
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
FUNCTION    : heapify
DESCRIPTION : Inserts node inside the tree with proper insertion if needs to heapify
ARGUMENTS   : struct Node* root - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
void heapify(struct Node* root) {
    struct Node* smallest = root;
    struct Node* left = root->left;
    struct Node* right = root->right;

    if (left && left->data < smallest->data)
        smallest = left;

    if (right && right->data < smallest->data)
        smallest = right;

    if (smallest != root) {
        printf("\n***********\n");
        printTree(root, 0);
        printf("Press any key to continue... ");
        getche();
        printf("\n***********\n");
        swap(&root->data, &smallest->data);
        printf("\n***********\n");
        printTree(root, 0);
        printf("Press any key to continue... ");
        getche();
        printf("\n***********\n");
        heapify(smallest);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int extractMin(struct Node** root) {
    if (*root == NULL) {
        printf("Heap is empty\n");
        return -1;
    }

    int minValue = (*root)->data;

    // Find the rightmost node in the last level
    struct Node* lastNode;
    while ((*root)->right) {
        lastNode = *root;
        *root = (*root)->right;
    }

    if ((*root)->left) {
        (*root)->data = (*root)->left->data;
        free((*root)->left);
        (*root)->left = NULL;
    } else {
        if (lastNode) {
            lastNode->right = NULL;
        }
        free(*root);
        *root = NULL;
    }

    if (*root) {
        heapify(*root);
    }

    return minValue;
}
