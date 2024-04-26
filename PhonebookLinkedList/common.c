#include "common.h"
#include "phonebook.h"

void handleFileError(FILE *file, const char *filename)
{
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

void handleMemoryAllocationError(void *pointer)
{
    if (pointer == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
}

void updateTextFile(Phonebook *phonebook) {
    FILE *file = fopen("phonebook.txt", "w");
    handleFileError(file, "phonebook.txt");

    fprintf(file, "%-19s%-19s%-19s%-14s%-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    fprintf(file, "========================================================================================\n");

    ContactNode *current = phonebook->head;
    while (current != NULL) {
        fprintf(file, "%-19s%-19s%-19s%-14s%-19s\n", current->contact.firstName, current->contact.middleName, current->contact.lastName, current->contact.mobileNumber, current->contact.emailAddress);
        current = current->next;
    }

    fclose(file);
}
