#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#define ALPHABET 256

typedef struct trienode {
    char data; // Storing for printing purposes only
    struct trienode *children[ALPHABET];
    bool isEnd;
} trienode;

#endif // TRIE_H_INCLUDED
