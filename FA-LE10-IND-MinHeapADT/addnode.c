/*
============================================================================
FILE        : addnode.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Adds node to tree
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
FUNCTION    : createNode
DESCRIPTION : Creates node with spots for data
ARGUMENTS   : int value - value to be put in node
dataType variableName - brief description
RETURNS     : struct Node*
===========================================================================
*/
// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
============================================================================
FUNCTION    : insertNode
DESCRIPTION : Inserts node inside the tree with proper insertion if needs to balance
ARGUMENTS   : struct Node* root - pointer node of type struct Node
            int value - value to compare with in tree
dataType variableName - brief description
RETURNS     : struct Node*
===========================================================================
*/

// Function to add a node to the binary tree
void addNode(struct Node** root, int value) {
     struct Node* newNode = createNode(value);

    if (*root == NULL) {
        *root = newNode;
        printf("SUCCESS: node added\n");
        return;
    }

    struct Node* queue[100]; // Assuming max 100 nodes
    int front = 0, rear = -1;

    queue[++rear] = *root;

    while (front <= rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            printf("SUCCESS: node added\n");
            break; // Exit the loop after adding the node
        } else {
            queue[++rear] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            printf("SUCCESS: node added\n");
            break; // Exit the loop after adding the node
        } else {
            queue[++rear] = temp->right;
        }
    }

    // Heapify starting from the root after adding the node
    for (int i = (rear - 1) / 2; i >= 0; i--) {
        heapify(queue[i]);
    }
}

