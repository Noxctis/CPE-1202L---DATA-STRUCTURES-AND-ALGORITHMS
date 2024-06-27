#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "recursion.h"

int main()
{
    int choice,n,i,exponent;
    double result;
    char again;
    do
    {
        system("cls");
        printf("\nMain Menu:\n");
        printf("[1] Power\n");
        printf("[2] Factorial\n");
        printf("[3] Fibonacci\n");
        printf("[4] Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("\nPower Option\n\n");
                printf("Enter base: ");
                scanf(" %d", &n);
                printf("Enter exponent: ");
                scanf(" %d", &exponent);
                printf("\n");
                powerIter(n,exponent);
                printf("\n");
                printf("Power Recursive Results: ");
                result = powerRecur(n,exponent);
                printf("%.3lf ", result);
                printf("\n");
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case 2:
            do
            {
                printf("\nFactorial Option\n\n");
                do{
                printf("Enter limit: ");
                scanf(" %d", &n);
                printf("\n");
                fflush(stdin);
                } while (n < 0);
                factorialIter(n);
                printf("\n");
                printf("Factorial Sequence Recursive Results: ");
                for(i = 1; i <= n; i++)
                {
                    result = factorialRecur(i);
                    printf("%.0lf ", result);
                }
                printf("\n");
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case 3:
            do
            {
                printf("\nFibonacci Option\n\n");
                printf("Enter limit: ");
                scanf(" %d", &n);
                printf("\n");
                fibonacciIter(n);
                printf("\n");
                printf("Fibonacci Sequence Recursive Results: ");
                for(i = 1; i <= n; i++)
                {
                    result = fibonacciRecur(i);
                    printf("%.0lf ", result);
                }
                printf("\n");
                fflush(stdin);
                printf("\nAgain [Y/N]? ");
                scanf(" %c", &again);
            } while (again != 'N' && again != 'n');
            break;

        case 4:
            printf("Exiting.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
        fflush(stdin);
    } while (choice != 4);

    return 0;
}
