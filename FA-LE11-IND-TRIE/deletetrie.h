#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"
#ifndef DELETETRIE_H_INCLUDED
#define DELETETRIE_H_INCLUDED

void freetrie(trienode* node);
int check(trienode* root, char* word);
char* findlongest(trienode* root, char* word);
int leafnode(trienode* root, char* word);
trienode* deletetrie(trienode* root, char* word);
#endif // DELETETRIE_H_INCLUDED
