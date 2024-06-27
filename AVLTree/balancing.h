/*
============================================================================
FILE        : balacing.h
AUTHOR      : 
DESCRIPTION : Function Prototypes for balancing
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
#ifndef BALANCING_H_INCLUDED
#define BALANCING_H_INCLUDED

int max(int a, int b);
int height(struct Node* node);
int Balance(struct Node* node);
struct Node* LeftRotate(struct Node* z);
struct Node* RightRotate(struct Node* z);
struct Node* rotateCheck(struct Node* root, int value, int balance);

#endif // BALANCING_H_INCLUDED
