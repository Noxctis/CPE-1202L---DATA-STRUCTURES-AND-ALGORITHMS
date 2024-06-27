#ifndef QUEUEDLL_H
#define QUEUEDLL_H

#define MAX_NAME_LENGTH 25
#define MAX_NUMBER_LENGTH 15
#define MAX_EMAIL_LENGTH 25

typedef struct Contact {
    int id;
    char firstName[MAX_NAME_LENGTH];
    char middleName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char mobileNumber[MAX_NUMBER_LENGTH];
    char emailAddress[MAX_EMAIL_LENGTH];
} Contact;

typedef struct Node {
    struct Node *prev;
    Contact contact;
    struct Node *next;
} Node;

typedef struct {
    int counter;
    Node* top; // points to the top node of the list
    Node* end; // points to the end node of the list
} LinkedList;

void enqueue(LinkedList* list);
void dequeue(LinkedList* list);
void show(LinkedList* list);

#endif // QUEUEDLL_H

/*
Jeff Thomas Dotillos - Dequeue && Main
Chrys  Sean Sevilla - Enqueue && Show && queueDLL.h
*/
