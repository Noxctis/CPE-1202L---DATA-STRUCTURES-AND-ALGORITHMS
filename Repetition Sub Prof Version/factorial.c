/*
============================================================================
FILE        : factorial.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Calculations for both recursive and iterative for factorial
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
#include "factorial.h"

/*
============================================================================
FUNCTION    : factorialIter
DESCRIPTION : Calculates iteratively the factorial sequence
ARGUMENTS   : int n - inputted number
dataType variableName - brief description
RETURNS     : void
===========================================================================
*/
void factorialIter(int n)
{
    double factorial = 1, i;
    printf("Factorial Sequence Iterative Results: ");
    for (i = 1; i <= n; i++)
    {
        factorial *= i;
        printf("%.0lf ", factorial);
    }
    printf("\n");
}

/*
============================================================================
FUNCTION    : factorialRecur
DESCRIPTION : Calculates recursively the factorial sequence
ARGUMENTS   : int n - inputted number
dataType variableName - brief description
RETURNS     :double - the nth factorial
===========================================================================
*/
double factorialRecur(int n)
{
    double x;
    if (n == 0 || n == 1)
    {
        x = 1;
    }
    else
    {
        x = (double)n * factorialRecur(n - 1);
    }
    return x;
}
