#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "phonebook.h"
#include "common.h"

void deleteContact(Phonebook *phonebook)
{
    char deleteChoice;
    do
    {
        printf("\nSearch by Last Name [L] or Mobile No. [N]? ");
        scanf(" %c", &deleteChoice);

        switch (deleteChoice)
        {
        case 'L':
        case 'l':
            deleteByLastName(phonebook);
            break;
        case 'N':
        case 'n':
            deleteByMobileNo(phonebook);
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (deleteChoice != 'L' && deleteChoice != 'l' &&
             deleteChoice != 'N' && deleteChoice != 'n');
}

void deleteByLastName(Phonebook *phonebook)
{
    char searchLastName[20];
    printf("Input Last Name to delete: ");
    scanf("%19s", searchLastName);

    ContactNode *current = phonebook->head;
    ContactNode *prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->contact.lastName, searchLastName) == 0) {
            // Node found, perform the delete operation
            if (prev == NULL) {
                // If the node to be deleted is the head
                phonebook->head = current->next;
            } else {
                // If the node to be deleted is not the head
                prev->next = current->next;
            }

            free(current); // Free the memory occupied by the node
            printf("\nContact deleted successfully!\n");
            found = 1;
            break;
        }

        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("\nError: Last Name not found!\n");
    }
    updateTextFile(phonebook);
}

void deleteByMobileNo(Phonebook *phonebook)
{
    char searchMobileNo[15];
    printf("Input Mobile No. to delete: ");
    scanf("%14s", searchMobileNo);

    ContactNode *current = phonebook->head;
    ContactNode *prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->contact.mobileNumber, searchMobileNo) == 0) {
            // Node found, perform the delete operation
            if (prev == NULL) {
                // If the node to be deleted is the head
                phonebook->head = current->next;
            } else {
                // If the node to be deleted is not the head
                prev->next = current->next;
            }

            free(current); // Free the memory occupied by the node
            printf("\nContact deleted successfully!\n");
            found = 1;
            break;
        }

        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("\nError: Mobile No. not found!\n");
    }
    updateTextFile(phonebook);
}

