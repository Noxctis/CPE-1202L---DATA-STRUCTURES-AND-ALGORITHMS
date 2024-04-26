#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>

void handleFileError(FILE *file, const char *filename);
void handleMemoryAllocationError(void *pointer);

#endif // COMMON_H
