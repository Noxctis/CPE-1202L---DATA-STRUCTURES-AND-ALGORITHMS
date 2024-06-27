#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"
#include "common.h"

void addContact()
{
    char save;
    createContact *newContact = (createContact *)malloc(sizeof(createContact));

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
    free(newContact);
}
