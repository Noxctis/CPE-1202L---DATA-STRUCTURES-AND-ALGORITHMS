#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"
#include "common.h"

void editContact(Phonebook *phonebook)
{
    char searchChoice;
    do
    {
        printf("\nSearch by Last Name [L] or Mobile No. [N]? ");
        scanf(" %c", &searchChoice);
        switch (searchChoice)
        {
        case 'L':
        case 'l':
            changeByLastName(phonebook);
            break;
        case 'N':
        case 'n':
            changeByMobileNo(phonebook);
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (searchChoice != 'L' && searchChoice != 'l' &&
             searchChoice != 'N' && searchChoice != 'n');
}

void changeContactInfo(createContact *contact)
{
    char choice;
    do
    {
        printf("\nCHANGE WHAT?\n");
        printf("[F]irst name\n[M]iddle name\n[L]ast name\n[N]Mobile no.\n[E]mail address\nChoice? ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'F':
        case 'f':
            printf("Replace first name: ");
            scanf("%19s", contact->firstName);
            break;
        case 'M':
        case 'm':
            printf("Replace middle name: ");
            scanf("%19s", contact->middleName);
            break;
        case 'L':
        case 'l':
            printf("Replace last name: ");
            scanf("%19s", contact->lastName);
            break;
        case 'N':
        case 'n':
            printf("Replace mobile no.: ");
            scanf("%14s", contact->mobileNumber);
            break;
        case 'E':
        case 'e':
            printf("Replace email address: ");
            scanf("%19s", contact->emailAddress);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            while ((choice = getchar()) != '\n' && choice != EOF);
        }
    } while (choice != 'L' && choice != 'l' &&
             choice != 'M' && choice != 'm' &&
             choice != 'F' && choice != 'f' &&
             choice != 'N' && choice != 'n' &&
             choice != 'E' && choice != 'e');
}

void changeByLastName(Phonebook *phonebook)
{
    char searchLastName[20];
    printf("Input Last Name to change: ");
    scanf("%19s", searchLastName);

    ContactNode *current = phonebook->head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->contact.lastName, searchLastName) == 0) {
            // Node found, perform the change operation
            changeContactInfo(&current->contact);
            printf("Contact information changed successfully!\n");
            found = 1;
            break;
        }

        current = current->next;
    }

    if (!found) {
        printf("Error: Last Name not found!\n");
    }
    updateTextFile(phonebook);
}

void changeByMobileNo(Phonebook *phonebook)
{
    char searchMobileNo[15];
    printf("Input Mobile No. to change: ");
    scanf("%14s", searchMobileNo);

    ContactNode *current = phonebook->head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->contact.mobileNumber, searchMobileNo) == 0) {
            // Node found, perform the change operation
            changeContactInfo(&current->contact);
            printf("Contact information changed successfully!\n");
            found = 1;
            break;
        }

        current = current->next;
    }

    if (!found) {
        printf("Error: Mobile No. not found!\n");
    }
    updateTextFile(phonebook);
}
