#ifndef STACKSLL_H
#define STACKSLL_H

#define MAX_NAME_LENGTH 25
#define MAX_NUMBER_LENGTH 15
#define MAX_EMAIL_LENGTH 25

typedef struct Contact {
    char firstName[MAX_NAME_LENGTH];
    char middleName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char mobileNumber[MAX_NUMBER_LENGTH];
    char emailAddress[MAX_EMAIL_LENGTH];
} Contact;

typedef struct Node {
    Contact contact;
    struct Node* next;
} Node;

typedef struct {
    Node* top; // points to the top node of the list
} LinkedList;

void push(LinkedList* list);
void pop(LinkedList* list);
void show(LinkedList* list);

#endif // STACKSSL_H
