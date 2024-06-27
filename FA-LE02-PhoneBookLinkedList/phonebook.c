#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"
#include "common.h"

Phonebook* createPhonebook() {
    Phonebook *phonebook = (Phonebook *)malloc(sizeof(Phonebook));
    handleMemoryAllocationError(phonebook);
    phonebook->head = NULL;

    FILE* file = fopen("phonebook.txt", "w+");
    if (file != NULL) {
        fprintf(file, "%-19s%-19s%-19s%-14s%-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
        fprintf(file, "==========================================================================================\n\n");
        fclose(file);
    } else {
        handleFileError(file, "phonebook.txt");
    }
    printf("Phonebook created successfully.\n");
    return phonebook;
}
