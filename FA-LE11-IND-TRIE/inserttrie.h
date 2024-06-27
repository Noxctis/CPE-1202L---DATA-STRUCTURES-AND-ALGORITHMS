#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "trie.h"
#ifndef INSERTTRIE_H_INCLUDED
#define INSERTTRIE_H_INCLUDED

trienode *createNode(char data);
bool trieInsert(trienode **root, char *str);

#endif // INSERTTRIE_H_INCLUDED
