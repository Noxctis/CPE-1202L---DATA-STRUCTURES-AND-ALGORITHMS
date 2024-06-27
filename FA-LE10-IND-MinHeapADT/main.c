/*
============================================================================
FILE        : main.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Input/Output
COPYRIGHT   : 4 April 2024
REVISION HISTORY
Date:               By:
revision date
Description:
author         description of the change
revision date
.
.
.
revision date
author         description of the change
author         description of the change
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "addnode.h"
#include "delete.h"
#include "display.h"
#include "heapify.h"
#include "traversals.h"

/*
============================================================================
FUNCTION    : main
DESCRIPTION : Handles Input and output menu until exit
ARGUMENTS   : void - none
dataType variableName - brief description
RETURNS     : int
===========================================================================
*/

int main()
{
    struct Node *root = NULL;
    int choice, value;
    do
    {
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Insert a node\n");
        printf("[2] Delete a node\n");
        printf("[3] Traverse tree\n");
        printf("[4] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nInsert value to add: ");
            scanf("%d", &value);
            //root = insertNode(root, value);
            addNode(&root, value);
            heapify(root);
            printf("SUCCESS: node added\n");
            printf("\nCurrent AVL tree:\n");
            printTree(root, 0);
            //treeMode(root);
            printf("Press any key to continue... ");
            getche();
            break;
        case 2:
            value = deleteRoot(&root);
            printf("SUCCESS: node deleted\n");
            printf("\nCurrent AVL tree:\n");
            printTree(root, 0);
            //treeMode(root);
            printf("Press any key to continue... ");
            getche();
            break;
        case 3:
            printf("\n=== TRAVERSE TREE ===\n");
            printTree(root, 0);
            //treeMode(root);
            printf("Breadth-first: ");
            breadthFirstTraversal(root);
            printf("\nInorder Traversal: ");
            inorderTraversal(root);
            printf("\nPreorder Traversal: ");
            preorderTraversal(root);
            printf("\nPostorder Traversal: ");
            postorderTraversal(root);
            printf("\n\nPress any key to continue... ");
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
