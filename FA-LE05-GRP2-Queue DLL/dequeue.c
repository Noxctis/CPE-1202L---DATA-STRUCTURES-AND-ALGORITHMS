#include <stdio.h>
#include <stdlib.h>
#include "queueSLL.h"

void dequeue(LinkedList* list) {
    if (list->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Node *temp = list->top;
    list->top = list->top->next;
    if (list->top != NULL){
        list->top->prev = NULL;
        }
    list->counter--;

    printf("Contact removed:\n");
    printf("# %-19s %-19s %-19s %-14s %-19s\n", "Last Name", "First Name", "Middle Name",  "Mobile No.", "Email Address");
    printf("========================================================================================\n");
    printf("%d %-19s %-19s %-19s %-14s %-19s\n",temp->contact.id, temp->contact.lastName, temp->contact.firstName, temp->contact.middleName, temp->contact.mobileNumber, temp->contact.emailAddress);

    printf("\nRecord Number: %d\n", temp->contact.id);
    printf("\nFirst Name: %s\n", temp->contact.firstName);
    printf("\nMiddle Name: %s\n", temp->contact.middleName);
    printf("\nLast Name: %s\n", temp->contact.lastName);
    printf("\nMobile No.: %s\n", temp->contact.mobileNumber);
    printf("\nEmail Address: %s\n", temp->contact.emailAddress);
    while (temp != NULL) {
       temp->contact.id--;
       temp = temp->next;
    }
    free(temp);
}
