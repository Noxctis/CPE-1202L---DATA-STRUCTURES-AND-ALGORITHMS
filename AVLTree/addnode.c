/*
============================================================================
FILE        : addnode.c
AUTHOR      : 
DESCRIPTION : Adds node to tree
COPYRIGHT   : 25 March 2024
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
#include "addnode.h"
#include "balancing.h"
#include "delete.h"
#include "display.h"
#include "search.h"
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
    newNode->height = 1;
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
// Function to add a node to the binary search tree
struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    else
    {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = Balance(root); // Find balance factor
    root = rotateCheck(root, value, balance);
    return root;
}
