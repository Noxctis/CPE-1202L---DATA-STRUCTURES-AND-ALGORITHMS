/*
============================================================================
FILE        : delete.c
AUTHOR      : Sid Andre Bordario
DESCRIPTION : Deletes the node and balances if imbalanced.
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
FUNCTION    : deleteNode
DESCRIPTION : Deletes specified node and balances if unbalanced
ARGUMENTS   : struct Node* root - pointer node of type struct Node
			int value - value to compare with in tree
dataType variableName - brief description
RETURNS     : struct Node*
===========================================================================
*/
// Function to delete a node from the binary search tree
struct Node *deleteNode(struct Node *root, int value)
{
	if (root == NULL)
	{
		printf("There is no node to be deleted\n");
		return root;
	}
	if (value < root->data)
	{
		root->left = deleteNode(root->left, value);
	}
	else if (value > root->data)
	{
		root->right = deleteNode(root->right, value);
	}
	else
	{
		if (root->right == NULL && root->left == NULL) // No child case
		{
			free(root);	 // node to be deleted
			root = NULL; // Current node is set to null
		}

		else if (root->left != NULL && root->right == NULL) // One child case
		{
			struct Node *temp = root->left; // Assign non-null child to temp
			root = root->left;				// Move content of non-null child to current node
			free(temp);						// Free non-null child
		}

		else if (root->right != NULL && root->left == NULL) // One child case
		{
			struct Node *temp = root->right; // Assign non-null child to temp
			root = root->right;				 // Move content of non-null child to current node
			free(temp);						 // Free non-null child
		}

		else // Delete case with two children
		{
			struct Node *temp = minValueNode(root->right); // Find smallest value on right subtree(leftmost in right)
			// struct Node* temp =  maxValueNode(root->left); //Find biggest value on left subtree(rightmost in left)
			root->data = temp->data;						   // Move value to current node
			root->right = deleteNode(root->right, temp->data); // Delete node containing min value
															   // root->left = deleteNode(root->left, temp->data); // Delete node containing max value
		}
	}
	if (root == NULL) // Return if tree only has one node after deletion
	{
		return root;
	}
	root->height = 1 + max(height(root->left), height(root->right)); // Update height for root

	int balance = Balance(root); // Find balance factor

	// Left Left Case
	if (balance > 1 && Balance(root->left) >= 0)
		return RightRotate(root);

	// Right Right Case
	if (balance < -1 && Balance(root->right) <= 0)
		return LeftRotate(root);

	// Left Right Case
	if (balance > 1 && Balance(root->left) < 0)
	{
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}

	// Right Left Case
	if (balance < -1 && Balance(root->right) > 0)
	{
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}
	return root;
}
