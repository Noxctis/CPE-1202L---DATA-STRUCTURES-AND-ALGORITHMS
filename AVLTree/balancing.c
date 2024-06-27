/*
============================================================================
FILE        : balancing.c
AUTHOR      : 
DESCRIPTION : Balances tree every insert
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
FUNCTION    : rotateCheck
DESCRIPTION : Creates node with spots for data
ARGUMENTS   : struct Node* root - pointer node of type struct Node
			int value - value to compare with in tree
			int balance - value to compare if balanced
dataType variableName - brief description
RETURNS     : struct Node*
===========================================================================
*/
struct Node *rotateCheck(struct Node *root, int value, int balance)
{
	// Node becomes unbalanced, then there are 4 cases
	//  Left Left Case
	if (balance > 1 && value < root->left->data)
	{
		return RightRotate(root);
	}
	// Right Right Case
	if (balance < -1 && value > root->right->data)
	{
		return LeftRotate(root);
	}
	// Left Right Case
	if (balance > 1 && value > root->left->data)
	{
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}

	// Right Left Case
	if (balance < -1 && value < root->right->data)
	{
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}

	return root;
}

/*
============================================================================
FUNCTION    : max
DESCRIPTION : Compares two numbers which are the larger one.
ARGUMENTS   :int a - value to compare
			int b - value to compare
dataType variableName - brief description
RETURNS     : int
===========================================================================
*/
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
/*
============================================================================
FUNCTION    : height
DESCRIPTION : Checks inside the node the height
ARGUMENTS   : struct Node* node - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : int
===========================================================================
*/
int height(struct Node *node)
{
	if (node == NULL)
		return 0;

	return node->height;
}
/*
============================================================================
FUNCTION    : Balance
DESCRIPTION : Calculates the balance of the tree
ARGUMENTS   : struct Node* node - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : int
===========================================================================
*/
int Balance(struct Node *node)
{
	if (node == NULL)
		return 0;

	return height(node->left) - height(node->right);
}

/*
============================================================================
FUNCTION    : LeftRotate
DESCRIPTION : Rotates tree to the left if imbalanced
ARGUMENTS   : struct Node* z - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : struct Node*
===========================================================================
*/
struct Node *LeftRotate(struct Node *z)
{
	struct Node *y = z->right;
	struct Node *t2 = y->left;

	// Perform Rotation
	y->left = z;
	z->right = t2;

	// Update heights of z and y
	z->height = max(height(z->left), height(z->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	// Return new root right child
	return y;
}
/*
============================================================================
FUNCTION    : RightRotate
DESCRIPTION : Rotates tree to the right if imbalanced
ARGUMENTS   : struct Node* z - pointer node of type struct Node
dataType variableName - brief description
RETURNS     : struct Node*
===========================================================================
*/
struct Node *RightRotate(struct Node *z)
{
	struct Node *y = z->left;
	struct Node *t3 = y->right;

	// Perform Rotation
	y->right = z;
	z->left = t3;

	// Update heights of z and y
	z->height = max(height(z->left), height(z->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	// Return new root left child
	return y;
}
