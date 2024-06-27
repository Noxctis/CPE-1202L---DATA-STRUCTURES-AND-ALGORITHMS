#include <stdio.h> 
#include <stdlib.h>
#include "stackSLL.h"

void show(LinkedList* list) {
    if (list->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%-19s %-19s %-19s %-14s %-19s\n", "Last Name", "First Name", "Middle Name",  "Mobile No.", "Email Address");
    printf("========================================================================================\n");
    Node* current = list->top;
    while (current != NULL) {
        printf("%-19s %-19s %-19s %-14s %-19s\n", current->contact.lastName, current->contact.firstName, current->contact.middleName, current->contact.mobileNumber, current->contact.emailAddress);
        current = current->next;
    }
    printf("========================================================================================\n");
}
