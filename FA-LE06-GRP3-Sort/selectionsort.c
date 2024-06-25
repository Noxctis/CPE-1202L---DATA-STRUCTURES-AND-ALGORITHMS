#include "swap.h"
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n)
{
    static int i = 0;
    static int minIndex = 0;

    if (i < n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
        i++;
        //printf("1");
        //printf("\t%d\t", i);
        minIndex = i;
    }
    else
    {
        i = 0; // Reset i for future calls
    }
}
