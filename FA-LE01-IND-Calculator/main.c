/*
============================================================================
 FILE        : .c
 AUTHOR      : Chrys Sean T. Sevilla
 DESCRIPTION : Multi-File Calculator
 COPYRIGHT   : January 28, 2024
 REVISION HISTORY
 Date:               By: 	        Description:
January 29, 2024	    Me              Made the program
 revision date	    author         description of the change
 .
 .
 .
 revision date	    author         description of the change
============================================================================
*/

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "calculator.h"

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Execute the main program
 ARGUMENTS   : none / void
 RETURNS     : int - exit code
===========================================================================
*/

int main()
{
    char choice = ' ', again;
    do
    {
        system("cls");
        printf("CALCULATOR MENU:\n");
        printf("[A]ddition\n");
        printf("[S]ubtraction\n");
        printf("[M]ultiplication\n");
        printf("[D]ivision\n");
        printf("[E]xit\n");
        printf("Choice?: ");
        scanf("%c", &choice);
        choice = toupper(choice);
        switch (choice)
        {
        case 'A':
            do
            {
                printf("\n[A]ddition\n");
                addMenu();
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &again);
                again = toupper(again);
            } while (again != 'N');
            break;
        case 'S':
            do
            {
                printf("\n[S]ubtraction\n");
                subtractMenu();
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &again);
                again = toupper(again);
            } while (again != 'N');
            break;
        case 'M':
            do
            {
                printf("\n[M]ultiplication\n");
                multiplyMenu();
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &again);
                again = toupper(again);
            } while (again != 'N');
            break;
        case 'D':
            do
            {
                printf("\n[D]ivision\n");
                divideMenu();
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf("%c", &again);
                again = toupper(again);
            } while (again != 'N');
            break;
        case 'E':
            printf("Exiting the calculator. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            getche();
        }
        fflush(stdin);
    } while (choice != 'E');

    return 0;
}
