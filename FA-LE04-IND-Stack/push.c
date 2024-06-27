#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackSLL.h"

void push(LinkedList* list) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
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

    newNode->next = NULL; // Initialize next pointer

    newNode->next = list->top;
    list->top = newNode;
}
