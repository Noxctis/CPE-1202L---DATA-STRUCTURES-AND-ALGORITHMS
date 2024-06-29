#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, GraphVertex* vertex) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    if (queue->rear) {
        queue->rear->next = newNode;
    } else {
        queue->front = newNode;
    }
    queue->rear = newNode;
}

GraphVertex* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    GraphVertex* vertex = temp->vertex;
    queue->front = queue->front->next;
    if (!queue->front) {
        queue->rear = NULL;
    }
    free(temp);
    return vertex;
}
