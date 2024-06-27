/*
============================================================================
FILE        : addnode.h
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Function Prototypes for addnode
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
#ifndef ADDNODE_H_INCLUDED
#define ADDNODE_H_INCLUDED

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *createNode(int value);
void addNode(struct Node** root, int value);
#endif // ADDNODE_H_INCLUDED

