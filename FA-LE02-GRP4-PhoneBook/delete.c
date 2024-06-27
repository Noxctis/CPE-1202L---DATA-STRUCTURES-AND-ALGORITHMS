#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "phonebook.h"
#include "common.h"

void deleteContact()
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
            deleteByLastName();
            break;
        case 'N':
        case 'n':
            deleteByMobileNo();
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (deleteChoice != 'L' && deleteChoice != 'l' &&
             deleteChoice != 'N' && deleteChoice != 'n');
}

void deleteByLastName()
{
    char deleteLastName[20];
    printf("Input Last Name: ");
    scanf("%19s", deleteLastName);

    FILE *inputFile = fopen("phonebook.txt", "r+");
    handleFileError(inputFile, "phonebook.txt");

    FILE *tempFile = fopen("temp.txt", "w");

    fscanf(inputFile, "%*[^\n]");
    fgetc(inputFile);
    fscanf(inputFile, "%*[^\n]");
    fgetc(inputFile);

    fprintf(tempFile, "%-19s%-19s%-19s%-14s%-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    fprintf(tempFile, "========================================================================================\n");
    if (tempFile != NULL)
    {
        createContact *contact = (createContact *)malloc(sizeof(createContact));

        int found = 0;

        while (fscanf(inputFile, "%19s %19s %19s %14s %19s", contact->firstName, contact->middleName, contact->lastName, contact->mobileNumber, contact->emailAddress) == 5)
        {
            if (strcmp(contact->lastName, deleteLastName) == 0)
            {
                found = 1;
                printf("%s/%s LastName/Mobile No. successfully deleted!\n", contact->lastName, contact->mobileNumber);
            }
            else
            {
                fprintf(tempFile, "%-19s %-19s %-19s %-14s %-19s\n", contact->firstName, contact->middleName, contact->lastName, contact->mobileNumber, contact->emailAddress);
            }
        }

        if (!found)
        {
            printf("Error: Last Name not found!\n");
        }

        free(contact);
        fclose(tempFile);
    }
    else
    {
        printf("Error creating temporary file.\n");
    }

    fclose(inputFile);

    remove("phonebook.txt");
    rename("temp.txt", "phonebook.txt");
}

void deleteByMobileNo()
{
    char deleteMobileNo[15];
    printf("Input Mobile No.: ");
    scanf("%14s", deleteMobileNo);

    FILE *inputFile = fopen("phonebook.txt", "r+");
    handleFileError(inputFile, "phonebook.txt");

    FILE *tempFile = fopen("temp.txt", "w");

    fscanf(inputFile, "%*[^\n]");
    fgetc(inputFile);
    fscanf(inputFile, "%*[^\n]");
    fgetc(inputFile);

    fprintf(tempFile, "%-19s%-19s%-19s%-14s%-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    fprintf(tempFile, "========================================================================================\n");
    if (tempFile != NULL)
    {
        createContact *contact = (createContact *)malloc(sizeof(createContact));

        int found = 0;

        while (fscanf(inputFile, "%19s %19s %19s %14s %19s", contact->firstName, contact->middleName, contact->lastName, contact->mobileNumber, contact->emailAddress) == 5)
        {
            if (strcmp(contact->mobileNumber, deleteMobileNo) == 0)
            {
                found = 1;
                printf("%s/%s LastName/Mobile No. successfully deleted!\n", contact->lastName, contact->mobileNumber);
            }
            else
            {
                fprintf(tempFile, "%-19s %-19s %-19s %-14s %-19s\n", contact->firstName, contact->middleName, contact->lastName, contact->mobileNumber, contact->emailAddress);
            }
        }

        if (!found)
        {
            printf("Error: Mobile No. not found!\n");
        }

        free(contact);
        fclose(tempFile);
    }
    else
    {
        printf("Error creating temporary file.\n");
    }

    fclose(inputFile);

    remove("phonebook.txt");
    rename("temp.txt", "phonebook.txt");
}
