#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "heaptree.h"

// Function to create a new node
struct Node* createNode(char word[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->word, word);
    newNode->weight = calculateWeight(word);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to calculate the weight of a word
int calculateWeight(char word[]) {
    int weight = 0;
    for (int i = 0; i < 3; ++i) {
        weight += (word[i] - 'A' + 1);
    }
    return weight;
}
