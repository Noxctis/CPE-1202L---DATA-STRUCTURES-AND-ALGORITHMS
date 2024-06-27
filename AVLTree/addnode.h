/*
============================================================================
FILE        : addnode.h
AUTHOR      : Sid Andre Bordario
DESCRIPTION : Function Prototypes for addnode
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
#ifndef ADDNODE_H_INCLUDED
#define ADDNODE_H_INCLUDED

struct Node
{
	int data;
	int height;
	struct Node *left;
	struct Node *right;
};

struct Node *createNode(int value);
struct Node *insertNode(struct Node *root, int value);

#endif // ADDNODE_H_INCLUDED
