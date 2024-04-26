#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"
#include "common.h"

void displayPhonebook(Phonebook *phonebook)
{

    char browseChoice;
    do
    {
        printf("\n[B] Browse All\n[L] Browse by Last Name\n[N] Browse by Mobile No.\nChoice? ");
        scanf(" %c", &browseChoice);

        switch (browseChoice)
        {
        case 'B':
        case 'b':
            browseAll(phonebook);
            break;
        case 'L':
        case 'l':
            browseByLastName(phonebook);
            break;
        case 'N':
        case 'n':
            browseByMobileNo(phonebook);
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
        fflush(stdin);
    } while (browseChoice != 'B' && browseChoice != 'b' &&
             browseChoice != 'L' && browseChoice != 'l' &&
             browseChoice != 'N' && browseChoice != 'n');
}

void browseAll(Phonebook *phonebook)
{
    ContactNode *current = phonebook->head;

    printf("%-19s %-19s %-19s %-14s %-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    printf("========================================================================================\n");

    while (current != NULL)
    {
        printf("%-19s %-19s %-19s %-14s %-19s\n",current->contact.firstName,current->contact.middleName,current->contact.lastName,current->contact.mobileNumber,current->contact.emailAddress);

        current = current->next;
    }
}

void browseByLastName(Phonebook *phonebook)
{
    char searchLastName[20];
    printf("Input Last Name: ");
    scanf("%19s", searchLastName);

    ContactNode *current = phonebook->head;
    int found = 0;

    printf("%-19s %-19s %-19s %-14s %-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    printf("========================================================================================\n");

    while (current != NULL)
    {
        if (strcmp(current->contact.lastName, searchLastName) == 0)
        {
            printf("%-19s %-19s %-19s %-14s %-19s\n",current->contact.firstName,current->contact.middleName,current->contact.lastName,current->contact.mobileNumber,current->contact.emailAddress);
            found = 1;
        }

        current = current->next;
    }

    if (!found)
    {
        printf("Error: Last Name not found!\n");
    }
}

void browseByMobileNo(Phonebook *phonebook)
{
    char searchMobileNo[15];
    printf("Input Mobile No.: ");
    scanf("%14s", searchMobileNo);

    ContactNode *current = phonebook->head;
    int found = 0;

    printf("%-19s %-19s %-19s %-14s %-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    printf("========================================================================================\n");

    while (current != NULL)
    {
        if (strcmp(current->contact.mobileNumber, searchMobileNo) == 0)
        {
            printf("%-19s %-19s %-19s %-14s %-19s\n",current->contact.firstName,current->contact.middleName,current->contact.lastName,current->contact.mobileNumber,current->contact.emailAddress);
            found = 1;
        }

        current = current->next;
    }

    if (!found)
    {
        printf("Error: Mobile No. not found!\n");
    }
}
