#include "common.h"

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
