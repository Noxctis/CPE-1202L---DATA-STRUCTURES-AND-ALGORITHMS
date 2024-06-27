/*
============================================================================
FILE        : traversals.c
AUTHOR      : 
DESCRIPTION : Traverse the tree
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
FUNCTION    : breadthFirstTraversal
DESCRIPTION : Traverses the tree breadth first
ARGUMENTS   : struct Node* root - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
// Function to perform breadth-first traversal
void breadthFirstTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[100]; // Assuming a maximum of 100 nodes for simplicity
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        struct Node *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

/*
============================================================================
FUNCTION    : inorderTraversal
DESCRIPTION : Traverses the tree inOrder/Infix Left Root Right
ARGUMENTS   : struct Node* root - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
// Function to traverse the binary tree in Inorder
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

/*
============================================================================
FUNCTION    : preorderTraversal
DESCRIPTION : Traverses the tree preOrder/Prefix Root Left Right
ARGUMENTS   : struct Node* root - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
// Function to traverse the binary tree in Preorder
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

/*
============================================================================
FUNCTION    : postorderTraversal
DESCRIPTION : Traverses the tree postOrder/Postfix Left Right Root
ARGUMENTS   : struct Node* root - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
// Function to traverse the binary tree in Postorder
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
