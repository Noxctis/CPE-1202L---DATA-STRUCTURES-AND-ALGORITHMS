#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "expressiontree.h"

// Function to push a node onto the stack
void push(Stack** top, Node* node) {
    Stack* new_node = (Stack*)malloc(sizeof(Stack));
    new_node->data = node;
    new_node->next = *top;
    *top = new_node;
}

// Function to pop a node from the stack
Node* pop(Stack** top) {
    if (*top == NULL) {
        return NULL;
    }
    Stack* temp = *top;
    *top = (*top)->next;
    Node* node = temp->data;
    free(temp);
    return node;
}
