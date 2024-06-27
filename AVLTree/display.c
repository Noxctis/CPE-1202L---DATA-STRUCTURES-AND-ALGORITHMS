/*
============================================================================
FILE        : display.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Display tree
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
#define MOVE_UP(x) printf("\e[%dA", x)
#define MOVE_DOWN(x) printf("\e[%dB", x)

/*
============================================================================
FUNCTION    : printTree
DESCRIPTION : Displays the tree horizontally
ARGUMENTS   : struct Node* root - pointer root of type struct Node
            int space - space to next node for display
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
// Function to print the text-based representation of the binary search tree
void printTree(struct Node *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

/*
============================================================================
FUNCTION    : treeMode
DESCRIPTION : Display binary tree vertically for all depth
ARGUMENTS   : struct Node* root - pointer root of type struct Node
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
void treeMode(struct Node *root)
{
    if (!root)
        return;

    int maxDepth = treeDepth(root, 1);

    for (int i = 0; i < maxDepth; i++)
        printf("\n");
    MOVE_UP(maxDepth);
    treeDisplay(root, 1);
    MOVE_DOWN(maxDepth);
    printf("\n");
}

/*
============================================================================
FUNCTION    : treeDepth
DESCRIPTION : Calculates the tree depth
ARGUMENTS   : struct Node* root - pointer root of type struct Node
            int depth - depth of the tree
dataType variableName - brief description
RETURNS     : int
===========================================================================
*/
int treeDepth(struct Node *root, int depth)
{
    if (!root)
        return depth - 1;

    int dLeft = treeDepth(root->left, depth + 1);
    int dRight = treeDepth(root->right, depth + 1);

    return (dLeft > dRight) ? dLeft : dRight;
}

/*
============================================================================
FUNCTION    : treeDisplay
DESCRIPTION : Display binary tree vertically on specific depth
ARGUMENTS   : struct Node* root - pointer root of type struct Node
            int depth - depth of the tree
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
void treeDisplay(struct Node *root, int depth)
{
    if (!root)
        return;

    treeDisplay(root->left, depth + 1);
    MOVE_DOWN(depth);
    printf("[%3d]%d", root->data, depth);
    MOVE_UP(depth);
    treeDisplay(root->right, depth + 1);
}
