#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queueSLL.h"

void enqueue(LinkedList* list) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->contact.id = ++list->counter;
    printf("Input First Name: ");
    fflush(stdin);
    gets(newNode->contact.firstName);
    printf("Input Middle Name: ");
    gets(newNode->contact.middleName);
    printf("Input Last Name: ");
    gets(newNode->contact.lastName);
    printf("Input Mobile No.: ");
    gets(newNode->contact.mobileNumber);
    printf("Input Email Address: ");
    gets(newNode->contact.emailAddress);

    newNode->prev = NULL; // Initialize prev pointer
    newNode->next = NULL; // Initialize next pointer

    if (list->top == NULL) {
        list->top = newNode;
        list->end = newNode;
    } else {
        list->end->next = newNode;
        newNode->prev = list->end;
        list->end = newNode;
    }
}

