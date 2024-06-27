/*
============================================================================
FILE        : search.c
AUTHOR      : Cristoffer Roger Requirme
DESCRIPTION : Search the tree
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
FUNCTION    : minValueNode
DESCRIPTION : Finds the minimum value node in tree
ARGUMENTS   : struct Node* node - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : struct Node*
===========================================================================
*/
// Function to find the minimum value node in a binary search tree
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    // Traverse down the left side of the tree to find the minimum value
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/*
============================================================================
FUNCTION    : maxValueNode
DESCRIPTION : Finds maximum value in tree
ARGUMENTS   : struct Node* node - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : struct Node*
===========================================================================
*/
struct Node *maxValueNode(struct Node *node)
{

    struct Node *current = node;
    while (current->right != NULL) // find the largest value in a binary search tree
    {
        current = current->right;
    }
    return current;
}
/*
============================================================================
FUNCTION    : findNumber
DESCRIPTION : Checks if number exists in tree
ARGUMENTS   : struct Node* root - pointer node of type struct Node
            int value - value to check
dataType variableName - brief description
RETURNS     : bool
===========================================================================
*/
bool findNumber(struct Node *root, int value)
{

    if (root == NULL)
    {
        return false;
    }
    if (value == root->data)
    {
        return true;
    }
    if (value < root->data)
    {
        return findNumber(root->left, value);
    }
    if (value > root->data)
    {
        return findNumber(root->right, value);
    }
    return;
}
