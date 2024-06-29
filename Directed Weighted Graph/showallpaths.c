#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void addPath(PathList* pathList, char path[], int weight) {
    PathNode* newPath = (PathNode*)malloc(sizeof(PathNode));
    strcpy(newPath->path, path);
    newPath->weight = weight;
    newPath->next = pathList->head;
    pathList->head = newPath;
    pathList->count++;
}

void dfsPaths(GraphVertex* vertex, char path[], int pathLen, int currentWeight, PathList* pathList) {
    vertex->processed = 1;
    path[pathLen] = vertex->data;
    path[pathLen + 1] = '\0';
    pathLen++;

    GraphArc* arc = vertex->firstArc;
    int isLeaf = 1;
    while (arc) {
        if (!arc->destination->processed) {
            isLeaf = 0;
            dfsPaths(arc->destination, path, pathLen, currentWeight + arc->weight, pathList);
        }
        arc = arc->nextArc;
    }

    if (isLeaf) {
        addPath(pathList, path, currentWeight);
    }

    pathLen--;
    path[pathLen] = '\0';
    vertex->processed = 0;
}

void ShowAllPaths(GraphHead* graph, PathList* pathList) {
    GraphVertex* vertex = graph->first;
    while (vertex) {
        vertex->processed = 0; // Reset processed flag
        vertex = vertex->nextVertex;
    }

    char path[MAX_NODES];

    vertex = graph->first;
    while (vertex) {
        if (!vertex->processed) {
            dfsPaths(vertex, path, 0, 0, pathList);
        }
        vertex = vertex->nextVertex;
    }

    printf("All Paths:\n");
    PathNode* current = pathList->head;
    while (current) {
        printf("Path: %s = %d\n", current->path, current->weight);
        current = current->next;
    }
}

void findLongestPath(PathList* pathList) {
    int maxWeight = -1;
    char longestPath[MAX_NODES] = "";

    PathNode* current = pathList->head;
    while (current) {
        if (current->weight > maxWeight) {
            maxWeight = current->weight;
            strcpy(longestPath, current->path);
        }
        current = current->next;
    }

    printf("Longest Path: %s = %d\n", longestPath, maxWeight);
}
