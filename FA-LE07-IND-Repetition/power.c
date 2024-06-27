#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

void powerIter(int n, int exponent){
    double result = 1;
    double base = (double)n;
    printf("Power Iterative Results: ");
    // For negative exponents
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }
    // Multiply base with itself exponent times
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    printf("%.3lf ", result);
}

double powerRecur(int n, int exponent){
    double base = (double)n;
    double result;
    //exponent is 0, return 1
    if (exponent == 0){
        result = 1;
    }
    // For negative exponents
    else if (exponent < 0){
        result = 1 / powerRecur(base, -exponent);
    }
    // Recursive compute power
    else{
        result = base * powerRecur(base, exponent - 1);
    }
    return result;
}



