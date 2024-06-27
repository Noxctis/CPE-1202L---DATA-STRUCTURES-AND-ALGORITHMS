#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void breadthFirstTraversal(struct Node* root);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
void printTree(struct Node* root, int space);
struct Node* deleteNode(struct Node* root, int value);
struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int value);
struct Node* minValueNode(struct Node* node);

#endif // BINARYSEARCHTREE_H_INCLUDED
