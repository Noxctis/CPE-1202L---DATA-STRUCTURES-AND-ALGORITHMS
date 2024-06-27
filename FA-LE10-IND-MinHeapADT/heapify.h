/*
============================================================================
FILE        : heapify.h
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Function Prototypes for heapify
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
#ifndef HEAPIFY_H_INCLUDED
#define HEAPIFY_H_INCLUDED

void heapify(struct Node* root);
void swap(int* a, int* b);
int extractMin(struct Node** root);

#endif // HEAPIFYS_H_INCLUDED
