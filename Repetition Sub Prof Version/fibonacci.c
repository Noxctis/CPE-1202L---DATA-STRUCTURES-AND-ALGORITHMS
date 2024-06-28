/*
============================================================================
FILE        : fibonacci.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Calculations for both recursive and iterative for fibonacci
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
#include "fibonacci.h"

/*
============================================================================
FUNCTION    : fibonacciIter
DESCRIPTION : Calculates iteratively the fibonacci sequence
ARGUMENTS   : int n - inputted number
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
void fibonacciIter(int n)
{
    int i;
    double fibonacci = 0, x = 0, y = 1;
    printf("Fibonacci Sequence Iterative Results: ");
    for (i = 1; i <= n; i++)
    {
        if (i <= 1)
        {
            fibonacci = i;
        }
        else
        {
            fibonacci = x + y;
            // Formula for the next term of fibonacci is the previous term plus the current term.
            x = y;
            // Assigns x to the previous term
            y = fibonacci;
            // Assigns y to the current term
        }
        printf("%.0lf ", fibonacci);
    }
}

/*
============================================================================
FUNCTION    : fibonacciRecur
DESCRIPTION : Calculates recursively the fibonacci sequence
ARGUMENTS   : int n - inputted number
dataType variableName - brief description
RETURNS     :double - the nth fibonacci
===========================================================================
*/
double fibonacciRecur(int n)
{
    double x;
    if (n <= 1)
    {
        x = n;
    }
    else
    {
        x = fibonacciRecur(n - 1) + fibonacciRecur(n - 2);
    }
    return x;
}
