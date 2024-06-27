#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "expressiontree.h"

// Function to evaluate the expression tree based on user input
double evaluate(Node* node, Variable* variables, int varCount, int* step) {
    if (node == NULL) {
        return 0;
    }
    if (!isOperator(node->data)) {
        for (int i = 0; i < varCount; i++) {
            if (node->data == variables[i].name) {
                return variables[i].value;
            }
        }
        return node->data - '0';
    }
    double left_val = evaluate(node->left, variables, varCount, step);
    double right_val = evaluate(node->right, variables, varCount, step);
    double result = 0;
    switch (node->data) {
        case '+': result = left_val + right_val; break;
        case '-': result = left_val - right_val; break;
        case '*': result = left_val * right_val; break;
        case '/': result = left_val / right_val; break;
        case '^': result = pow(left_val, right_val); break;
        case '=': result = right_val; break;
    }
    printf("Step %d: %c = %.2lf %c %.2lf\n", (*step)++, node->data, left_val, node->data, right_val);
    return result;
}

// Function to identify variables in the expression
int identifyVariables(char* infix, Variable* variables) {
    int varCount = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalpha(infix[i])) {
            int found = 0;
            for (int j = 0; j < varCount; j++) {
                if (variables[j].name == infix[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                variables[varCount++].name = infix[i];
            }
        }
    }
    return varCount;
}
