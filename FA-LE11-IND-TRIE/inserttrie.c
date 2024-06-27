#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "deletetrie.h"
#include "display.h"
#include "inserttrie.h"
#include "trie.h"


trienode *createNode(char data) {
    trienode *newNode = (trienode *) malloc(sizeof *newNode);
    for(int i = 0; i < ALPHABET; i++)
        newNode->children[i] = NULL;
    newNode->isEnd = false;
    newNode->data = data;
    return newNode;
}

bool trieInsert(trienode **root, char *str) {
    if(*root == NULL)
        *root = createNode('\0');

    trienode *temp = *root;
    int length = strlen(str);

    for(int i = 0; i < length; i++) {
        int index = str[i] - 'a';

        if(temp->children[index] == NULL)
            temp->children[index] = createNode(str[i]);

        temp = temp->children[index];
    }

    if(temp->isEnd)
        return false;

    temp->isEnd = true;

    return true;
}
