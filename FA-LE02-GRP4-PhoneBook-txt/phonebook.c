#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"
#include "common.h"

void createPhonebook()
{
    FILE *file = fopen("phonebook.txt", "w+");
    handleFileError(file, "phonebook.txt");

    fprintf(file, "%-19s%-19s%-19s%-14s%-19s\n", "First Name", "Middle Name", "Last Name", "Mobile No.", "Email Address");
    fprintf(file, "========================================================================================\n");
    fclose(file);
    printf("Phonebook created successfully.\n");
}
