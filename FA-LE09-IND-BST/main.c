#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "binarysearchtree.h"

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Insert a node\n");
        printf("[2] Delete a node\n");
        printf("[3] Traverse tree\n");
        printf("[4] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nInsert value to add: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("SUCCESS: node added\n");
                printf("\nCurrent binary search tree:\n");
                //printTree(root, 0);
                treeMode(root);
                printf("Press any key to continue... ");
                getche();
                break;
            case 2:
                printf("\nInsert value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("SUCCESS: node deleted\n");
                printf("\nCurrent binary search tree:\n");
                printTree(root, 0);
                printf("Press any key to continue... ");
                getche();
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
                printf("Press any key to continue... ");
                getche();
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
