#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Add new node\n");
        printf("[2] Delete a node\n");
        printf("[3] Traverse binary tree\n");
        printf("[4] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n=== ADD NEW NODE ===\n");
                printf("Insert value to add: ");
                scanf("%d", &value);
                addNode(&root, value);
                //printTree(root, 0);
                treeMode(root);
                break;
            case 2:
                printf("\n=== DELETE NODE ===\n");
                printf("Insert value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printTree(root, 0);
                treeMode(root);
                break;
            case 3:
                printf("\n=== TRAVERSE TREE ===\n");
                printf("Breadth-first: ");
                breadthFirstTraversal(root);
                printf("\nInorder Traversal: ");
                inorderTraversal(root);
                printf("\nPreorder Traversal: ");
                preorderTraversal(root);
                printf("\nPostorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
