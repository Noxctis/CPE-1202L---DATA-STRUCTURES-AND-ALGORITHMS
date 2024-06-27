#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"
#include "common.h"

void editContact()
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
            searchByLastName();
            break;
        case 'N':
        case 'n':
            searchByMobileNo();
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (searchChoice != 'L' && searchChoice != 'l' &&
             searchChoice != 'N' && searchChoice != 'n');
}

void changeContactInfo(FILE *file, createContact *contact)
{
    char choice;
    do
    {
        printf("\nCHANGE WHAT?\n");
        printf("[F]irst name\n[M]iddle name\n[L]ast name\n[N] mobile no.\n[E]mail address\nChoice? ");
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
            while ((choice = getchar()) != '\n' && choice != EOF)
                ;
        }
    } while (choice != 'L' && choice != 'l' &&
             choice != 'M' && choice != 'm' &&
             choice != 'F' && choice != 'f' &&
             choice != 'N' && choice != 'n' &&
             choice != 'E' && choice != 'e');
}

void searchByLastName()
{
    char searchLastName[20];
    printf("Input Last Name: ");
    scanf("%19s", searchLastName);

    FILE *file = fopen("phonebook.txt", "r+");
    handleFileError(file, "phonebook.txt");

    char line[100];
    int found = 0;

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
                printf("%-19s%-19s%-19s%-14s%-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
                printf("========================================================================================\n");
                printf("%-19s%-19s%-19s%-14s%-19s\n", firstName, middleName, lastName, mobileNo, emailAddress);
                found = 1;

                createContact *contact = malloc(sizeof(createContact));
                handleMemoryAllocationError(contact);

                strcpy(contact->firstName, firstName);
                strcpy(contact->middleName, middleName);
                strcpy(contact->lastName, lastName);
                strcpy(contact->mobileNumber, mobileNo);
                strcpy(contact->emailAddress, emailAddress);

                changeContactInfo(file, contact);

                fseek(file, -length - 1, SEEK_CUR);
                fprintf(file, "%-19s%-19s%-19s%-14s%-19s\n", contact->firstName, contact->middleName, contact->lastName, contact->mobileNumber, contact->emailAddress);

                printf("Contact information changed successfully!\n");
                free(contact);

                break;
            }
        }
    }

    if (!found)
    {
        printf("Error: Last Name not found!\n");
    }

    fclose(file);
}

void searchByMobileNo()
{
    char searchMobileNo[15];
    printf("Input Mobile No.: ");
    scanf("%14s", searchMobileNo);

    FILE *file = fopen("phonebook.txt", "r+");
    handleFileError(file, "phonebook.txt");

    char line[100];
    int found = 0;

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
                printf("%-19s%-19s%-19s%-14s%-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
                printf("========================================================================================\n");
                printf("%-19s%-19s%-19s%-14s%-19s\n", firstName, middleName, lastName, mobileNo, emailAddress);
                found = 1;

                createContact *contact = malloc(sizeof(createContact));
                handleMemoryAllocationError(contact);

                strcpy(contact->firstName, firstName);
                strcpy(contact->middleName, middleName);
                strcpy(contact->lastName, lastName);
                strcpy(contact->mobileNumber, mobileNo);
                strcpy(contact->emailAddress, emailAddress);

                changeContactInfo(file, contact);

                fseek(file, -length - 1, SEEK_CUR);

                fprintf(file, "%-19s%-19s%-19s%-14s%-19s\n", contact->firstName, contact->middleName, contact->lastName, contact->mobileNumber, contact->emailAddress);

                printf("Contact information changed successfully!\n");

                free(contact);

                break;
            }
        }
    }

    if (!found)
    {
        printf("Error: Mobile No. not found!\n");
    }

    fclose(file);
}
