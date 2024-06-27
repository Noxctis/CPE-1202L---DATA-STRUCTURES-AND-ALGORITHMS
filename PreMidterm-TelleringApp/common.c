#include <stdio.h>
#include <stdlib.h>
#include "payment.h"
#include "common.h"

void handleMemoryAllocationError(void *pointer)
{
    if (pointer == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
}
