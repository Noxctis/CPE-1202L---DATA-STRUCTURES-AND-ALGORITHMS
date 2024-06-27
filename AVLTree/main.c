/*
============================================================================
FILE        : main.c
AUTHOR      : Chrys Sean Sevilla
DESCRIPTION : Input/Output
COPYRIGHT   : 25 March 2024
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
#include "balancing.h"
#include "delete.h"
#include "display.h"
#include "search.h"
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
    int choice, value, search;
    do
    {
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Insert a node\n");
        printf("[2] Delete a node\n");
        printf("[3] Search a node\n");
        printf("[4] Traverse tree\n");
        printf("[5] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nInsert value to add: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            printf("SUCCESS: node added\n");
            printf("\nCurrent AVL tree:\n");
            // printTree(root, 0);
            treeMode(root);
            printf("Press any key to continue... ");
            getche();
            break;
        case 2:
            printf("\nInsert value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("SUCCESS: node deleted\n");
            printf("\nCurrent AVL tree:\n");
            // printTree(root, 0);
            treeMode(root);
            printf("Press any key to continue... ");
            getche();
            break;
        case 3:
            printf("[1] Requested node\n");
            printf("[2] Smallest node\n");
            printf("[3] Largest node\n");
            printf("Choice? ");
            scanf("%d", &search);

            switch (search)
            {
            case 1:
                printf("\nInsert value to search: ");
                scanf("%d", &value);
                if (findNumber(root, value) == 1)
                {
                    printf("True/Exists\n");
                }
                else if (findNumber(root, value) == 0)
                {
                    printf("False/Does not exist\n");
                }
                printf("%d (%d)\n", value, findNumber(root, value));
                printf("Press any key to continue... ");
                getche();
                fflush(stdin);
                break;
            case 2:
                printf("\nSmallest node search: ");
                if (root != NULL)
                {
                    struct Node *smallest = minValueNode(root);
                    printf("%d\n", smallest->data);
                }
                else
                {
                    printf("The tree is empty.\n");
                }
                printf("Press any key to continue... ");
                getche();
                fflush(stdin);
                break;
            case 3:
                printf("\nLargest node to search: ");
                if (root != NULL)
                {
                    struct Node *largest = maxValueNode(root);
                    printf("%d\n", largest->data);
                }
                else
                {
                    printf("The tree is empty.\n");
                }
                printf("Press any key to continue... ");
                getche();
                fflush(stdin);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                fflush(stdin);
            }
            break;
        case 4:
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
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
