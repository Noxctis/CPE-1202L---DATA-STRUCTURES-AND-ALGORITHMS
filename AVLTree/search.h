/*
============================================================================
FILE        : search.h
AUTHOR      : 
DESCRIPTION : Function Prototypes for search
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

#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include <stdbool.h>

bool findNumber(struct Node *root, int value);
struct Node *minValueNode(struct Node *node);
struct Node *maxValueNode(struct Node *node);

#endif // SEARCH_H_INCLUDED
