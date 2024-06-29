#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void parseInput(GraphHead* graph, char str[]) {
    char *token = strtok(str, ",!");
    while (token != NULL) {
        char src = token[0];
        char dest = token[1];
        int weight = (token[2] - '0') * 10 + (token[3] - '0');
        addVertex(graph, src);
        addVertex(graph, dest);
        addEdge(graph, src, dest, weight);
        token = strtok(NULL, ",!");
    }
}
