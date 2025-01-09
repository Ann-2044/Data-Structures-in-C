#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjList[MAX];
    struct Node* revAdjList[MAX];
    bool visited[MAX];
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->revAdjList[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->revAdjList[dest];
    graph->revAdjList[dest] = newNode;
}

void dfsFillOrder(struct Graph* graph, int vertex, int* stack, int* top) {
    graph->visited[vertex] = true;
    struct Node* temp = graph->adjList[vertex];

    while (temp) {
        if (!graph->visited[temp->vertex]) {
            dfsFillOrder(graph, temp->vertex, stack, top);
        }
        temp = temp->next;
    }
    stack[(*top)++] = vertex;
}

void dfsOnReverseGraph(struct Graph* graph, int vertex, int* component, int* componentSize) {
    graph->visited[vertex] = true;
    component[*componentSize] = vertex;
    (*componentSize)++;

    struct Node* temp = graph->revAdjList[vertex];
    while (temp) {
        if (!graph->visited[temp->vertex]) {
            dfsOnReverseGraph(graph, temp->vertex, component, componentSize);
        }
        temp = temp->next;
    }
}

void findSCCs(struct Graph* graph) {
    int stack[MAX], top = 0;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            dfsFillOrder(graph, i, stack, &top);
        }
    }

    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = false;
    }

    printf("\nStrongly Connected Components:\n");

    while (top > 0) {
        int vertex = stack[--top];
        if (!graph->visited[vertex]) {
            int component[MAX], componentSize = 0;
            dfsOnReverseGraph(graph, vertex, component, &componentSize);

            for (int i = 0; i < componentSize - 1; i++) {
                for (int j = i + 1; j < componentSize; j++) {
                    if (component[i] > component[j]) {
                        int temp = component[i];
                        component[i] = component[j];
                        component[j] = temp;
                    }
                }
            }

            printf("SCC: ");
            for (int i = 0; i < componentSize; i++) {
                printf("%d ", component[i]);
            }
            printf("\n");
        }
    }
}

int main() {
    int vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    findSCCs(graph);

    return 0;
}
