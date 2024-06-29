#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define MAX_NODES 26 // Assuming only uppercase English letters as nodes

typedef struct GraphArc {
    struct GraphVertex* destination;
    struct GraphArc* nextArc;
    int weight;
} GraphArc;

typedef struct GraphVertex {
    char data;
    int indegree;
    int outdegree;
    int processed;
    struct GraphVertex* nextVertex;
    GraphArc* firstArc;
} GraphVertex;

typedef struct {
    int count;
    GraphVertex* first;
} GraphHead;

typedef struct PathNode {
    char path[MAX_NODES];
    int weight;
    struct PathNode* next;
} PathNode;

typedef struct {
    PathNode* head;
    int count;
} PathList;

typedef struct QueueNode {
    GraphVertex* vertex;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Graph structure and related functions
void initGraph(GraphHead* graph);
GraphVertex* findVertex(GraphHead* graph, char data);
void addVertex(GraphHead* graph, char data);
void addEdge(GraphHead* graph, char src, char dest, int weight);
void parseInput(GraphHead* graph, char str[]);

// Functions for displaying graph representations
void ShowAdjMatrix(GraphHead* graph);
void ShowAdjList(GraphHead* graph);
void bfs(GraphHead* graph);

// Path finding and longest path functions
void addPath(PathList* pathList, char path[], int weight);
void dfsPaths(GraphVertex* vertex, char path[], int pathLen, int currentWeight, PathList* pathList);
void ShowAllPaths(GraphHead* graph, PathList* pathList);
void findLongestPath(PathList* pathList);

// Queue structure and related functions for BFS
void initQueue(Queue* queue);
int isQueueEmpty(Queue* queue);
void enqueue(Queue* queue, GraphVertex* vertex);
GraphVertex* dequeue(Queue* queue);

#endif // GRAPH_H_INCLUDED
