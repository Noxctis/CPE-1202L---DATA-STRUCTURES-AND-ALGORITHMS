#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 15

typedef struct Contact
{
    char firstName[MAX_NAME_LENGTH];
    char middleName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char mobileNumber[MAX_NUMBER_LENGTH];
    char emailAddress[MAX_NAME_LENGTH];
} createContact;

typedef struct ContactNode {
    createContact contact;
    struct ContactNode *next;
} ContactNode;

typedef struct {
    ContactNode *head;
} Phonebook;

void updateTextFile(Phonebook *phonebook);
Phonebook *createPhonebook();

void displayPhonebook(Phonebook *phonebook);
void browseAll(Phonebook *phonebook);
void browseByLastName(Phonebook *phonebook);
void browseByMobileNo(Phonebook *phonebook);

void addContact(Phonebook* phonebook);

void editContact(Phonebook *phonebook);
void changeContactInfo(createContact *contact);
void changeByLastName(Phonebook *phonebook);
void changeByMobileNo(Phonebook *phonebook);

void deleteContact(Phonebook *phonebook);
void deleteByLastName(Phonebook *phonebook);
void deleteByMobileNo(Phonebook *phonebook);

#endif // PHONEBOOK_H

