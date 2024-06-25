#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include "swap.h"

int main()
{
    int arr[10], arr2[10], arr3[10];
    int n = 0;

    printf("Input random values: ");

    char input[100];
    fgets(input, sizeof(input), stdin);

    // Parsing input string and storing values into array
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (token[0] == '!') {
            break;
        }
        arr[n++] = atoi(token); // Convert string to integer
        token = strtok(NULL, " ");
    }

    // Check if the '!' marker was found
    if (token == NULL || token[0] != '!') {
        printf("No terminator marker '!' found. Exiting program.\n");
        return 1;
    }

    memcpy(arr2, arr, sizeof(int) * n);
    memcpy(arr3, arr, sizeof(int) * n);
    int i;
    int doneBubble = 0;
    int doneSelection = 0;
    int doneInsertion = 0;
    bool sortedbubble = false;
    bool sortedselection = false;
    bool sortedinsertion = false;
    bool sortedall = false;
    printf("%-7s %-10s %-15s\t\t %-15s\t\t\t\t %-15s\n","PASS", "ITERATION", "EXCHANGE SORT", "SELECTION SORT", "INSERTION SORT");

    do{

        if (sortedbubble == false){
                //printf("\n");
        bubbleSort(arr, n);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                sortedbubble = false;
                for (int i = 0; i < n; i++)
        {
            printf("%-3d", arr[i]);
        }
        if(sortedinsertion == true){
                printf("%-5s %-10s %-15s %-15s %-15s", "","","","","");
                for (int i = 0; i < n; i++)
        {
            printf("%-3d", arr3[i]);
        }
            }
                break;
            }
            else {
                sortedbubble = true;
            }
        }



        if(sortedselection == false){
                //printf("\n");
        selectionSort(arr2, n);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr2[i] > arr2[i + 1])
            {
                sortedselection = false;
                printf("%-5s %-10s", "","");
                for (int i = 0; i < n; i++)
                {
                printf("%-3d", arr2[i]);
                }
                break;
            }
            else {
                    sortedselection = true;

            }
        }

        if(sortedinsertion == false){
        //printf("\n");
        insertionSort(arr3, n);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr3[i] > arr3[i + 1])
            {
                sortedinsertion = false;

            if(sortedselection == true){
                printf("%-5s %-10s %-s", "","", "");
                for (int i = 0; i < n; i++)
        {
            printf("%-3d", arr2[i]);
        }

            }
                printf("%-5s %-10s %-15s %-15s %-15s", "","","","","");
        for (int i = 0; i < n; i++)
        {
            printf("%-3d", arr3[i]);
        }
                break;
            }
            else{
                sortedinsertion = true;
            }
        }


        sortedall = sortedbubble&&sortedselection&&sortedinsertion;

        if(sortedbubble == true){
             for (int i = 0; i < n; i++)
        {
            printf("%-3d", arr[i]);
        }
            printf("\n");
        printf("%-5s %-10s %-15s %-15s %-15s", "","","done","","","");
        }

        getchar();
    }while(!sortedall);
    return 0;
}
