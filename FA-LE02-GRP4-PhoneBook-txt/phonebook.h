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

void createPhonebook();

void displayPhonebook();
void browseAll();
void browseByLastName();
void browseByMobileNo();

void addContact();

void editContact();
void changeContactInfo(FILE *file, createContact *contact);
void searchByLastName();
void searchByMobileNo();

void deleteContact();
void deleteByLastName();
void deleteByMobileNo();

#endif // PHONEBOOK_H
