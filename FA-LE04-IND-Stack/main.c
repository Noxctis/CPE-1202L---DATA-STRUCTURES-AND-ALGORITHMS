#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stackSLL.h"

int main()
{
    LinkedList list;
    list.top = NULL;
    char choice;
    char again;
    do
    {
        system("cls");
        printf("\nSTACK ADT - SLL MENU:\n");
        printf("[1] Push\n");
        printf("[2] Pop\n");
        printf("[3] Show\n");
        printf("[4] Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice)
        {
        case '1':
            do
            {
                push(&list);
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case '2':
            do
            {
                pop(&list);
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case '3':

                show(&list);
                printf("\nPress any key to return to MAIN MENU ");
                getche();
                fflush(stdin);


            break;

        case '4':
            printf("Exiting Stack.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
        fflush(stdin);
    } while (choice != '4');

    return 0;
}

