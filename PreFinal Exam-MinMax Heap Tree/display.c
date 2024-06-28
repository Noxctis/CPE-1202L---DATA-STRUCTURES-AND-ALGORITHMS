#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "heaptree.h"

// Function to display heap as a tree
void displayHeap(struct Node* root, int depth) {
    if (root) {
        depth +=10;
        displayHeap(root->right, depth);
        for (int i = 10; i < depth; i++) {
            printf(" ");
        }
        printf("%s (%02d)\n", root->word, root->weight);
        displayHeap(root->left, depth);
    }
}
