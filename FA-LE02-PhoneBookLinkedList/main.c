// main.c

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "phonebook.h"

int main()
{
    Phonebook *phonebook = createPhonebook();
    getche();
    char choice;
    char again;
    do
    {
        system("cls");
        printf("\nPhonebook Menu:\n");
        printf("[A]ppend\n");
        printf("[B]rowse\n");
        printf("[C]hange\n");
        printf("[D]elete\n");
        printf("[E]xit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice)
        {
        case 'B':
        case 'b':
            do
            {
                displayPhonebook(phonebook);
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case 'A':
        case 'a':
            do
            {
                addContact(phonebook);
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case 'C':
        case 'c':
            do
            {
                editContact(phonebook);
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case 'D':
        case 'd':
            do
            {
                deleteContact(phonebook);
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case 'E':
        case 'e':
            printf("Exiting Phonebook.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
        fflush(stdin);
    } while (choice != 'E' && choice != 'e');

    return 0;
}
