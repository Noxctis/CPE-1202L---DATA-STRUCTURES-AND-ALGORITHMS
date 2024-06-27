#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "deletetrie.h"
#include "display.h"
#include "inserttrie.h"
#include "trie.h"

void freetrie(trienode* node) {
    for(int i=0; i<ALPHABET; i++) {
        if (node->children[i] != NULL) {
            freetrie(node->children[i]);
        }
        else {
            continue;
        }
    }
    free(node);
}

int check(trienode* root, char* word) {
    trienode* temp = root;
    int len = strlen(word);
    if (len == 0)
        return 0;
    int last_index = 0;
    for (int i=0; i < len; i++) {
        int position = word[i] - 'a';
        if (temp->children[position]) {

            for (int j=0; j<ALPHABET; j++) {
                if (j != position && temp->children[j]) {

                    last_index = i + 1;
                    break;
                }
            }

            temp = temp->children[position];
        }
    }
    return last_index;
}

char* findlongest(trienode* root, char* word) {

    if (!word || word[0] == '\0')
        return NULL;

    int len = strlen(word);

    char* longest_prefix = (char*) calloc (len + 1, sizeof(char));
    for (int i=0; word[i] != '\0'; i++)
        longest_prefix[i] = word[i];
    longest_prefix[len] = '\0';


    int branch_idx  = check(root, longest_prefix) - 1;
    if (branch_idx >= 0) {

        longest_prefix[branch_idx] = '\0';
        longest_prefix = (char*) realloc (longest_prefix, (branch_idx + 1) * sizeof(char));
    }

    return longest_prefix;
}

int leafnode(trienode* root, char* word) {

    trienode* temp = root;
    for (int i=0; word[i]; i++) {
        int position = (int) word[i] - 'a';
        if (temp->children[position]) {
            temp = temp->children[position];
        }
    }
    return temp->isEnd;
}

trienode* deletetrie(trienode* root, char* word) {

    if (!root)
        return NULL;
    if (!word || word[0] == '\0')
        return root;

    if (!leafnode(root, word)) {
        return root;
    }
    trienode* temp = root;
    char* longest_prefix = findlongest(root, word);
    printf("Longest Prefix = %s\n", longest_prefix);
    if (longest_prefix[0] == '\0') {
        free(longest_prefix);
        return root;
    }
    int i;
    for (i=0; longest_prefix[i] != '\0'; i++) {
        int position = (int) longest_prefix[i] - 'a';
        if (temp->children[position] != NULL) {
            temp = temp->children[position];
        }
        else {
            free(longest_prefix);
            return root;
        }
    }
    int len = strlen(word);
    for (; i < len; i++) {
        int position = (int) word[i] - 'a';
        if (temp->children[position]) {
            trienode* rm_node = temp->children[position];
            temp->children[position] = NULL;
            freetrie(rm_node);
        }
    }

    if (leafnode(root,word)) {
        // Set all pointers to NULL
        for (i = 0; i < ALPHABET; i++) {
            if (root->children[i]) {
                root->children[i] = NULL;
            }
        }
    }

    free(longest_prefix);

    return root;
}

