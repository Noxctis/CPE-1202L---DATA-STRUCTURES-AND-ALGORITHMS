#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

GraphVertex* findVertex(GraphHead* graph, char data) {
    GraphVertex* vertex = graph->first;
    while (vertex != NULL && vertex->data != data) {
        vertex = vertex->nextVertex;
    }
    return vertex;
}

void addVertex(GraphHead* graph, char data) {
    if (findVertex(graph, data) == NULL) {
        GraphVertex* newVertex = (GraphVertex*)malloc(sizeof(GraphVertex));
        newVertex->data = data;
        newVertex->indegree = 0;
        newVertex->outdegree = 0;
        newVertex->processed = 0;
        newVertex->nextVertex = graph->first;
        newVertex->firstArc = NULL;
        graph->first = newVertex;
        graph->count++;
    }
}

void addEdge(GraphHead* graph, char src, char dest, int weight) {
    GraphVertex* srcVertex = findVertex(graph, src);
    GraphVertex* destVertex = findVertex(graph, dest);
    if (srcVertex != NULL && destVertex != NULL) {
        GraphArc* newArc = (GraphArc*)malloc(sizeof(GraphArc));
        newArc->destination = destVertex;
        newArc->weight = weight;
        newArc->nextArc = srcVertex->firstArc;
        srcVertex->firstArc = newArc;
        srcVertex->outdegree++;
        destVertex->indegree++;
    }
}

void initGraph(GraphHead* graph) {
    graph->count = 0;
    graph->first = NULL;
}

