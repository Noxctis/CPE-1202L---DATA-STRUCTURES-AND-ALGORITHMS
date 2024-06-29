#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void ShowAdjList(GraphHead* graph) {
    printf("Adjacency List:\n");
    GraphVertex* vertex = graph->first;
    while (vertex) {
        printf("%c ->", vertex->data);
        GraphArc* arc = vertex->firstArc;
        while (arc) {
            printf(" %c(%d)", arc->destination->data, arc->weight);
            arc = arc->nextArc;
        }
        printf("\n");
        vertex = vertex->nextVertex;
    }
}
