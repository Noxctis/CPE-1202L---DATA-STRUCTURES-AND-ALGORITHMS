#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value);
void addNode(struct Node** root, int value);
void breadthFirstTraversal(struct Node* root);
struct Node* deleteNode(struct Node* root, int value);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
void printTree(struct Node* root, int level);
#endif // BINARYTREE_H_INCLUDED
