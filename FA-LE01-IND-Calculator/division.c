#include <stdio.h>

/*
============================================================================
 FUNCTION    : divide
 DESCRIPTION : Calculates the two quotient of two numbers
 ARGUMENTS   : none / void
 RETURNS     : int - divided numbers
===========================================================================
*/

float divide(int x, int y)
{
    float answer;
    if (y != 0)
    {
        answer = (float)x / (float)y;
    }
    else
    {
        // Handle division by zero error
        printf("Error: Division by zero\n");
        answer = 0.0;
    }

    return answer;
}
