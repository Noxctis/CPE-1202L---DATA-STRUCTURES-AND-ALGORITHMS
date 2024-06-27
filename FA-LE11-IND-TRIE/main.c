#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "deletetrie.h"
#include "display.h"
#include "inserttrie.h"
#include "trie.h"

int main() {
    int choice;
    trienode *root = NULL;
    char str[100];
    char again;

    do {
        printMenu();
        printf("Choice? ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                do {

                    printf("Insert word to add: ");
                    scanf("%s", str);
                    trieInsert(&root, str);
                    printf("\nTrie after adding '%s':\n", str);
                    display(root,0);
                    printf("\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while(again == 'Y' || again == 'y');
                break;
            case 2:
                do {
                    printf("Insert word to delete: ");
                    scanf("%s", str);
                    if (leafnode(root, str)) {
                        deletetrie(root, str);
                        printf("'%s' deleted successfully.\n", str);
                        printf("\nTrie after deleting '%s':\n", str);
                        display(root,0);

                    } else {
                        printf("'%s' not found.\n", str);
                    }

                    printf("\nAgain [Y/N]? ");
                    scanf(" %c", &again);
                } while(again == 'Y' || again == 'y');
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);
    freetrie(root);
    return 0;
}
