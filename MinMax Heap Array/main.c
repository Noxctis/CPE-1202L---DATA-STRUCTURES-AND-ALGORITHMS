#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heaparray.h"

int main() {
    struct Node maxHeap[MAX_SIZE], minHeap[MAX_SIZE];
    int maxHeapSize = 0, minHeapSize = 0;
    char choice;

    do {
        printf("=== MAIN MENU ===\n");
        printf("[1] Add new node\n");
        printf("[2] Delete root from Max Heap\n");
        printf("[3] Delete root from Min Heap\n");
        printf("Choice? ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                char newWord[4];
                printf("=== ADD NEW NODE ===\n");
                printf("Insert value to add: ");
                scanf("%s", newWord);

                int weight = calculateWeight(newWord);

                addToMaxHeap(maxHeap, &maxHeapSize, newWord);
                addToMinHeap(minHeap, &minHeapSize, newWord);

                printf("%s = %02d\n", newWord, weight);

                printf("Max Heap:\n");
                displayHeap(maxHeap, maxHeapSize, 1, 0, 0);

                printf("Min Heap:\n");
                displayHeap(minHeap, minHeapSize, 0, 0, 0);

                printf("Again[y/n]? ");
                scanf(" %c", &choice);
                break;
            }
            case '2': {
                if (maxHeapSize > 0) {
                    printf("=== DELETE ROOT FROM MAX HEAP ===\n");
                    deleteFromMaxHeap(maxHeap, &maxHeapSize);
                    printf("Max Heap after deletion:\n");
                    displayHeap(maxHeap, maxHeapSize, 1, 0, 0);
                } else {
                    printf("Max Heap is empty. Cannot delete root.\n");
                }
                printf("Again [y/n]? ");
                scanf(" %c", &choice);
                break;
            }
            case '3': {
                if (minHeapSize > 0) {
                    printf("=== DELETE ROOT FROM MIN HEAP ===\n");
                    deleteFromMinHeap(minHeap, &minHeapSize);
                    printf("Min Heap after deletion:\n");
                    displayHeap(minHeap, minHeapSize, 0, 0, 0);
                } else {
                    printf("Min Heap is empty. Cannot delete root.\n");
                }
                printf("Again [y/n]? ");
                scanf(" %c", &choice);
                break;
            }
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
