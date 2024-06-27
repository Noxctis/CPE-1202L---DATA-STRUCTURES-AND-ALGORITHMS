#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "expressiontree.h"

// Function to create a new tree node
Node* createNode(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '=';
}

// Function to get the precedence of an operator
int precedence(char c) {
    switch (c) {
        case '=': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return -1;
}

// Function to insert implicit multiplication signs
void insertImplicitMultiplication(char* infix, char* modifiedInfix) {
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        modifiedInfix[j++] = infix[i];
        if (isalpha(infix[i]) && (isdigit(infix[i+1]) || isalpha(infix[i+1]))) {
            modifiedInfix[j++] = '*';
        } else if (isdigit(infix[i]) && isalpha(infix[i+1])) {
            modifiedInfix[j++] = '*';
        }
    }
    modifiedInfix[j] = '\0';
}

// Function to convert infix expression to postfix using Shunting-yard algorithm
void infixToPostfix(char* infix, char* postfix) {
    Stack* operators = NULL;
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&operators, createNode(infix[i]));
        } else if (infix[i] == ')') {
            while (operators && operators->data->data != '(') {
                postfix[k++] = pop(&operators)->data;
            }
            pop(&operators); // Remove '('
        } else if (isOperator(infix[i])) {
            while (operators && precedence(operators->data->data) >= precedence(infix[i])) {
                postfix[k++] = pop(&operators)->data;
            }
            push(&operators, createNode(infix[i]));
        }
    }
    while (operators) {
        postfix[k++] = pop(&operators)->data;
    }
    postfix[k] = '\0';
}

// Function to construct an expression tree from a postfix expression
Node* constructTree(char* postfix) {
    Stack* stack = NULL;
    for (int i = 0; postfix[i]; i++) {
        Node* new_node = createNode(postfix[i]);
        if (isOperator(postfix[i])) {
            new_node->right = pop(&stack);
            new_node->left = pop(&stack);
        }
        push(&stack, new_node);
    }
    return pop(&stack);
}

// Function to free the expression tree
void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
