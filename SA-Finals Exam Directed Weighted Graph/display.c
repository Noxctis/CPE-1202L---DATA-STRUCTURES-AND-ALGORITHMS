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

void bfs(GraphHead* graph) {
    Queue queue;
    initQueue(&queue);
    GraphVertex* vertex = graph->first;
    while (vertex) {
        vertex->processed = 0; // Reset processed flag
        vertex = vertex->nextVertex;
    }

    vertex = graph->first;
    while (vertex) {
        if (!vertex->processed) {
            enqueue(&queue, vertex);
            while (!isQueueEmpty(&queue)) {
                GraphVertex* current = dequeue(&queue);
                if (!current->processed) {
                    printf("%c ", current->data);
                    current->processed = 1;
                    GraphArc* arc = current->firstArc;
                    while (arc) {
                        if (!arc->destination->processed) {
                            enqueue(&queue, arc->destination);
                        }
                        arc = arc->nextArc;
                    }
                }
            }
        }
        vertex = vertex->nextVertex;
    }
}
