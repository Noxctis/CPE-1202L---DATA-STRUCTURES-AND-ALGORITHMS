#include "swap.h"
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    static int i = 0;
    static int j = 0;
    static int passes = 0; // Number of passes

    if (passes == 0)
        passes = n - 1; // Set passes dynamically

    if (i < passes)
    {
        if (j < passes - i)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
            j++;
            printf("%-5d %-10d", i + 1,j);
        }
        else
        {
            i++;
            j = 0;
        }
    }
    else
    {
        i = 0; // Reset i, j, and passes for future calls
        j = 0;
        passes--;
    }
}
