#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"
#include "common.h"

void displayPhonebook()
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
            browseAll();
            break;
        case 'L':
        case 'l':
            browseByLastName();
            break;
        case 'N':
        case 'n':
            browseByMobileNo();
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (browseChoice != 'B' && browseChoice != 'b' &&
             browseChoice != 'L' && browseChoice != 'l' &&
             browseChoice != 'N' && browseChoice != 'n');
}

void browseAll()
{
    FILE *file = fopen("phonebook.txt", "r");
    handleFileError(file, "phonebook.txt");

    char line[100];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n')
        {
            line[length - 1] = '\0';
        }

        printf("%s\n", line);
    }
    printf("\n");
    fclose(file);
}

void browseByLastName()
{
    char searchLastName[20];
    printf("Input Last Name: ");
    scanf("%19s", searchLastName);

    FILE *file = fopen("phonebook.txt", "r");
    handleFileError(file, "phonebook.txt");

    char line[100];
    int found = 0;

    printf("%-19s %-19s %-19s %-14s %-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    printf("========================================================================================\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n')
        {
            line[length - 1] = '\0';
        }
        char firstName[20], middleName[20], lastName[20], mobileNo[15], emailAddress[20];
        if (sscanf(line, "%19[^, ] %19[^, ] %19[^, ] %14[^, ] %19[^, ]", firstName, middleName, lastName, mobileNo, emailAddress) == 5)
        {
            if (strcmp(lastName, searchLastName) == 0)
            {
                printf("%-19s %-19s %-19s %-14s %-19s\n", firstName, middleName, lastName, mobileNo, emailAddress);
                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("Error: Last Name not found!\n");
    }

    fclose(file);
}

void browseByMobileNo()
{
    char searchMobileNo[15];
    printf("Input Mobile No.: ");
    scanf("%14s", searchMobileNo);

    FILE *file = fopen("phonebook.txt", "r");
    handleFileError(file, "phonebook.txt");

    char line[100];
    int found = 0;

    printf("%-19s %-19s %-19s %-14s %-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    printf("========================================================================================\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n')
        {
            line[length - 1] = '\0';
        }

        char firstName[20], middleName[20], lastName[20], mobileNo[15], emailAddress[20];
        if (sscanf(line, "%19[^, ] %19[^, ] %19[^, ] %14[^, ] %19[^, ]", firstName, middleName, lastName, mobileNo, emailAddress) == 5)
        {
            if (strcmp(mobileNo, searchMobileNo) == 0)
            {
                printf("%-19s %-19s %-19s %-14s %-19s\n", firstName, middleName, lastName, mobileNo, emailAddress);
                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("Error: Mobile No. not found!\n");
    }

    fclose(file);
}
