#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "expressiontree.h"

int main() {
    char infix[100];
    char modifiedInfix[200];
    char postfix[200];
    Variable variables[10];

    printf("Enter a mathematical expression (e.g., z=5x^3 or z=5x^3+((7xy^2-3x)+9)): ");
    scanf("%s", infix);

    // Insert implicit multiplication signs
    insertImplicitMultiplication(infix, modifiedInfix);

    // Identify variables in the expression
    int varCount = identifyVariables(modifiedInfix, variables);

    // Get values for variables from the user
    for (int i = 0; i < varCount; i++) {
        printf("Enter the value of %c: ", variables[i].name);
        scanf("%lf", &variables[i].value);
    }

    // Convert infix to postfix
    infixToPostfix(modifiedInfix, postfix);

    // Construct the expression tree
    Node* root = constructTree(postfix);

    // Print the expression tree
    printf("Expression tree:\n");
    printTree(root, 0);

    // Print the inorder traversal of the expression tree
    printf("Inorder traversal of the expression tree: ");
    printInorder(root);
    printf("\n");

   // Evaluate the expression tree with step-by-step output
    int step = 1;
    double result = evaluate(root, variables, varCount, &step);
    printf("Result of the expression: %lf\n", result);

    // Assign the result to the left child variable if root is '='
    if (root->data == '=') {
        for (int i = 0; i < varCount; i++) {
            if (root->left->data == variables[i].name) {
                variables[i].value = result;
                printf("%c = %.2lf\n", variables[i].name, variables[i].value);
                break;
            }
        }
    }

    // Free the expression tree
    freeTree(root);

    return 0;
}
