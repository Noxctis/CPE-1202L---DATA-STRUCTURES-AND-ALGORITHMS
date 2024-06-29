#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void ShowAdjMatrix(GraphHead* graph) {
    int adjMatrix[MAX_NODES][MAX_NODES] = {0};

    GraphVertex* vertex = graph->first;
    while (vertex) {
        GraphArc* arc = vertex->firstArc;
        while (arc) {
            adjMatrix[vertex->data - 'A'][arc->destination->data - 'A'] = arc->weight;
            arc = arc->nextArc;
        }
        vertex = vertex->nextVertex;
    }

    printf("Adjacency Matrix:\n  ");
    for (int i = 0; i < MAX_NODES; i++) {
        printf(" %c ", 'A' + i);
    }
    printf("\n");

    for (int i = 0; i < MAX_NODES; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < MAX_NODES; j++) {
            printf("%02d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
