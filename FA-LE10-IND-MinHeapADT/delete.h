/*
============================================================================
FILE        : delete.h
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Function Prototypes for delete
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
#ifndef DELETE_H_INCLUDED
#define DELETE_H_INCLUDED

struct Node* deleteNode(struct Node* root, int value);
int deleteRoot(struct Node** root);
struct Node* getParentNode(struct Node* root, struct Node* child);

#endif // DELETE_H_INCLUDED

