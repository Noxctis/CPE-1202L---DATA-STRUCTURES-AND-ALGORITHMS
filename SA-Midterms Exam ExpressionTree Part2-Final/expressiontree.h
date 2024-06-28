#ifndef EXPRESSIONTREE_H_INCLUDED
#define EXPRESSIONTREE_H_INCLUDED

// Define the structure for a tree node
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Define the structure for a stack node
typedef struct Stack {
    Node* data;
    struct Stack* next;
} Stack;

// Define the structure for a variable
typedef struct Variable {
    char name;
    double value;
} Variable;

void printInorder(Node* node);
void printTree(Node* root, int space);
double evaluate(Node* node, Variable* variables, int varCount, int* step);
int identifyVariables(char* infix, Variable* variables);
Node* createNode(char data);
int isOperator(char c);
int precedence(char c);
void insertImplicitMultiplication(char* infix, char* modifiedInfix);
void infixToPostfix(char* infix, char* postfix);
Node* constructTree(char* postfix);
void freeTree(Node* node);
void push(Stack** top, Node* node);
Node* pop(Stack** top);


#endif // EXPRESSIONTREE_H_INCLUDED
