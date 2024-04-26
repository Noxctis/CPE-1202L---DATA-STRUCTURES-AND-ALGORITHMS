#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"
#include "common.h"

void addContact(Phonebook *phonebook)
{
    char save;
    ContactNode *newContactNode = (ContactNode *)malloc(sizeof(ContactNode));
    handleMemoryAllocationError(newContactNode);
    createContact *newContact = &(newContactNode->contact);

    printf("\nAPPEND MENU\n");
    printf("Input First Name: ");
    scanf("%19s", newContact->firstName);
    printf("Input Middle Name: ");
    scanf("%19s", newContact->middleName);
    printf("Input Last Name: ");
    scanf("%19s", newContact->lastName);
    printf("Input Mobile No.: ");
    scanf("%14s", newContact->mobileNumber);
    printf("Input Email Address.: ");
    scanf("%19s", newContact->emailAddress);

    newContactNode->next = NULL; // Initialize next pointer

    if (phonebook->head == NULL) {
        // If the list is empty, make the new node the head
        phonebook->head = newContactNode;
    } else {
        // Traverse the list to find the last node
        ContactNode *current = phonebook->head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Append the new contact at the end
        current->next = newContactNode;
    }

    printf("Save record [Y/N]?: ");
    scanf(" %c", &save);

    if (save == 'Y' || save == 'y')
    {
        FILE *file = fopen("phonebook.txt", "a+");
        if (file != NULL)
        {
            fprintf(file, "%-19s%-19s%-19s%-14s%-19s\n", newContact->firstName, newContact->middleName, newContact->lastName, newContact->mobileNumber, newContact->emailAddress);
            fclose(file);
            printf("Record saved successfully.\n");
        }
        else
        {
            handleFileError(file, "phonebook.txt");
        }
    }
}
