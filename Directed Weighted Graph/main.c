#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main() {
    char input[100];
    printf("Input a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    GraphHead graph;
    initGraph(&graph);
    parseInput(&graph, input);

    ShowAdjMatrix(&graph);
    printf("\n");
    ShowAdjList(&graph);
    printf("\nBFS Traversal:\n");
    bfs(&graph);

    printf("\n\nIdentifying all paths:\n");
    PathList pathList = {NULL, 0};
    ShowAllPaths(&graph, &pathList);

    printf("\nFinding the longest path:\n");
    findLongestPath(&pathList);

    return 0;
}
