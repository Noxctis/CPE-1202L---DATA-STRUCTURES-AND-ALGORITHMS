#include "swap.h"
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    static int i = 0;
    static int j = 0;

    if (i < n)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
        //printf("1");
        //printf("\t%d\t", i + 1);
        i++;
    }
    else
    {
        // Reset i and j for future calls
        i = 0;
        j = 0;
    }
}
