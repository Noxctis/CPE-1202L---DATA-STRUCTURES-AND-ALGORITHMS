#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "deletetrie.h"
#include "display.h"
#include "inserttrie.h"
#include "trie.h"

void display(trienode *root, int level) {
    if (root == NULL) {
        return;
    }
    level += 5;
    for (int i = 0; i < ALPHABET; i++) {
        if (root->children[i]) {
            display(root->children[i], level);
            printf("\n");
            for (int j = 5; j < level; j++) {
                printf(" ");
            }
            printf("%c", i + 'a');
            if (root->children[i]->isEnd) {
                printf("*\n");
            }
        }
    }
}

void printMenu() {
    printf("\n=== TRIE MAIN MENU ===\n");
    printf("[1] Add new word\n");
    printf("[2] Delete word\n");
    printf("[3] Exit\n");
    printf("=======================\n");
}
