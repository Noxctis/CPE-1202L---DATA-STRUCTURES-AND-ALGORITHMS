/*
============================================================================
FILE        : main.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Input/Output
COPYRIGHT   : 19 March 2024
REVISION HISTORY
Date:               By:
revision date
Description:
author         description of the change
revision date
.
.
.
revision date
author         description of the change
author         description of the change
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "sum.h"
#include "fibonacci.h"
#include "factorial.h"

int main()
{
    int n, i;
    double result;
    do
    {
        printf("Enter a number: ");
        scanf(" %d", &n);
        printf("\n");
    } while (n < 0);
    printf("\nFactorial Option\n\n");
    factorialIter(n);
    printf("\n");
    printf("Factorial Sequence Recursive Results: ");
    for (i = 1; i <= n; i++)
    {
        result = factorialRecur(i);
        printf("%.0lf ", result);
    }
    printf("\n");
    printf("\nFibonacci Option\n\n");
    fibonacciIter(n);
    printf("\n\n");
    printf("Fibonacci Sequence Recursive Results: ");
    for (i = 1; i <= n; i++)
    {
        result = fibonacciRecur(i);
        printf("%.0lf ", result);
    }
    printf("\n");
    printf("\nSum Option\n\n");
    sumIter(n);
    printf("\n");
    printf("Sum Series Recursive Results: ");
    for (i = 1; i <= n; i++)
    {
        result = sumRecur(i);
        printf("%.0lf ", result);
    }
    printf("\n");
    fflush(stdin);
    return 0;
}
