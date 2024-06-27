#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

double fibonacciRecur(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacciRecur(n - 1) + fibonacciRecur(n - 2);
}

// Function to calculate Fibonacci numbers iteratively
void fibonacciIter(int n) {
    int i;
    double fibonacci = 0, x = 0, y = 1;
    printf("Fibonacci Sequence Iterative Results: ");
    for (i = 1; i <= n; i++) {
        if (i <= 1){
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
