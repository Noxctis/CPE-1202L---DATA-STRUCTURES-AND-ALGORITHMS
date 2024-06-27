#include <stdio.h> 
#include <stdlib.h>
#include "recursion.h"

void factorialIter(int n){
    double factorial = 1, i;
    printf("Factorial Sequence Iterative Results: ");
    for(i = 1; i <= n; i++)
    {
        factorial *= i;
        printf("%.0lf ", factorial);
    }
    printf("\n");
}

double factorialRecur(int n){
    if (n == 0 || n == 1)
        return 1;
    else
        return (double)n * factorialRecur(n - 1);
}



