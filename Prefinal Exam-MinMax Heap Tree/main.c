#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "heaptree.h"

int main() {
    struct Node* maxHeapRoot = NULL;
    struct Node* minHeapRoot = NULL;
    char choice;
    char newWord[4];

    do {
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Add new node\n");
        printf("[2] Delete root from Max Heap and Min Heap\n");
        printf("[3] Exit\n");
        printf("Choice? ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {

                printf("=== ADD NEW NODE ===\n");
                printf("Insert three-character word to add: ");
                scanf("%s", newWord);

                int weight = calculateWeight(newWord);

                insertToMaxHeap(&maxHeapRoot, newWord);
                insertToMinHeap(&minHeapRoot, newWord);

                printf("%s = %02d\n", newWord, weight);

                printf("Max Heap:\n");
                displayHeap(maxHeapRoot, 0);

                printf("Min Heap:\n");
                displayHeap(minHeapRoot, 0);

                printf("Press any key to continue... ");
                getche();
                break;
            }
            case '2': {
                if (maxHeapRoot && minHeapRoot) {
                    printf("=== DELETE ROOT FROM MAX HEAP AND MIN HEAP ===\n");
                    maxHeapRoot = deleteRootMaxHeap(maxHeapRoot);
                    minHeapRoot = deleteRootMinHeap(minHeapRoot);

                    printf("Max Heap after deletion:\n");
                    displayHeap(maxHeapRoot, 0);

                    printf("Min Heap after deletion:\n");
                    displayHeap(minHeapRoot, 0);
                } else {
                    printf("One or both heaps are empty. Cannot delete root.\n");
                }
                printf("Press any key to continue... ");
                getche();
                break;
            }
            case '3': {
                printf("Exiting...\n");
                break;
            }
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != '3');

    return 0;
}
