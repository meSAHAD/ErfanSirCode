#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Structure to represent a directed graph
struct Graph
{
    int V;
    struct Node **adjList;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node **)malloc(V * sizeof(struct Node *));
    for (int i = 0; i < V; i++)
    {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to perform Depth-First Search and topological sorting
void topologicalSortDFS(struct Graph *graph, int v, int visited[], struct Node *stack)
{
    visited[v] = 1; // Mark the current vertex as visited

    struct Node *temp = graph->adjList[v];
    while (temp != NULL)
    {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
        {
            topologicalSortDFS(graph, adjVertex, visited, stack);
        }
        temp = temp->next;
    }

    // Push the current vertex to the stack
    struct Node *newNode = createNode(v);
    newNode->next = stack->next;
    stack->next = newNode;
}

// Function to perform topological sorting using Depth-First Search
void topologicalSort(struct Graph *graph)
{
    int visited[MAX_VERTICES] = {0};     // Initialize visited array to 0
    struct Node *stack = createNode(-1); // Create a stack with a sentinel node

    for (int i = 0; i < graph->V; i++)
    {
        if (!visited[i])
        {
            topologicalSortDFS(graph, i, visited, stack);
        }
    }

    // Print the topological order
    struct Node *temp = stack->next;
    printf("Topological Sort: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free the memory allocated for the stack
    free(stack);
}

int main()
{
    int V = 6; // Number of vertices in the graph
    struct Graph *graph = createGraph(V);

    // Adding edges to the graph
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    // Free the memory allocated for the graph
    for (int i = 0; i < V; i++)
    {
        struct Node *current = graph->adjList[i];
        while (current != NULL)
        {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}
