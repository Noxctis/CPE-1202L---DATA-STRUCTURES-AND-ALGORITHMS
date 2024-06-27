#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculator.h"

/*
============================================================================
 FUNCTION    : addMenu
 DESCRIPTION : Adds two numbers
 ARGUMENTS   : none / void
 RETURNS     : none / void
===========================================================================
*/

void addMenu(void)
{
    int num1, num2;
    printf("\nInput First Value: ");
    scanf("%d", &num1);
    printf("Input Second Value: ");
    scanf("%d", &num2);
    printf("\nSum of %d plus %d equals to %d\n", num1, num2, add(num1, num2));
}

/*
============================================================================
 FUNCTION    : subtractMenu
 DESCRIPTION : Subtracts two numbers
 ARGUMENTS   : none / void
 RETURNS     : none / void
===========================================================================
*/

void subtractMenu(void)
{
    int num1, num2;
    printf("\nInput First Value: ");
    scanf("%d", &num1);
    printf("Input Second Value: ");
    scanf("%d", &num2);
    printf("\nDifference of %d minus %d equals to %d\n", num1, num2, subtract(num1, num2));
}

/*
============================================================================
 FUNCTION    : multiplyMenu
 DESCRIPTION : Multiplies two numbers
 ARGUMENTS   : none / void
 RETURNS     : none / void
===========================================================================
*/

void multiplyMenu(void)
{
    int num1, num2;
    printf("\nInput First Value: ");
    scanf("%d", &num1);
    printf("Input Second Value: ");
    scanf("%d", &num2);
    printf("\nProduct of %d times %d equals to %d\n", num1, num2, multiply(num1, num2));
}

/*
============================================================================
 FUNCTION    : divideMenu
 DESCRIPTION : Divides two numbers
 ARGUMENTS   : none / void
 RETURNS     : none / void
===========================================================================
*/

void divideMenu(void)
{
    int num1, num2;
    printf("\nInput First Value: ");
    scanf("%d", &num1);
    printf("Input Second Value: ");
    scanf("%d", &num2);
    printf("\nQuotient of %d divided by %d equals to %.2f\n", num1, num2, divide(num1, num2));
}
