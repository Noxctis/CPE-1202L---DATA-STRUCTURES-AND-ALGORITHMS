/*
============================================================================
FILE        : sum.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Calculations for both recursive and iterative for sum series
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
#include "sum.h"

/*
============================================================================
FUNCTION    : sumIter
DESCRIPTION : Calculates iteratively the sum series
ARGUMENTS   : int n - inputted number
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
void sumIter(int n)
{
    int i;
    double sum = 0;
    printf("Sum Series Iterative Results: ");
    for (i = 1; i <= n; i++)
    {
        sum += i;
        printf("%.0lf ", sum);
    }
    printf("\n");
}

/*
============================================================================
FUNCTION    : sumRecur
DESCRIPTION : Calculates recursively the sum series
ARGUMENTS   : int n - inputted number
dataType variableName - brief description
RETURNS     :double - the nth sum series
===========================================================================
*/
double sumRecur(int n)
{
    double x;
    if (n > 0)
    {
        x = (double)n + sumRecur(n - 1);
    }
    else
    {
        x = 0;
    }
    return x;
}
