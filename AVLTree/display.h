/*
============================================================================
FILE        : display.h
AUTHOR      : 
DESCRIPTION : Function Prototypes for display
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

#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

void treeMode(struct Node *root);
int treeDepth(struct Node *root, int depth);
void treeDisplay(struct Node *root, int depth);
void printTree(struct Node *root, int space);

#endif // DISPLAY_H_INCLUDED
