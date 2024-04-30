#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_NODES 1000

typedef struct Node
{
    char name[MAX_LENGTH];
    struct Node *next;
} Node;

typedef struct Graph
{
    Node *adjList[MAX_NODES];
    int visited[MAX_NODES];
    char parent[MAX_NODES][MAX_LENGTH];
} Graph;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *q, char *name)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

char *dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    Node *temp = q->front;
    char *name = (char *)malloc(MAX_LENGTH * sizeof(char));
    if (name == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(name, q->front->name);
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return name;
}

Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (graph == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < MAX_NODES; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
        strcpy(graph->parent[i], "");
    }
    return graph;
}

void addEdge(Graph *graph, char *src, char *dest)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->name, dest);
    newNode->next = graph->adjList[src[0] - 'A'];
    graph->adjList[src[0] - 'A'] = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->name, src);
    newNode->next = graph->adjList[dest[0] - 'A'];
    graph->adjList[dest[0] - 'A'] = newNode;
}

int bfs(Graph *graph, char *src, char *dest)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    enqueue(q, src);
    graph->visited[src[0] - 'A'] = 1;
    while (q->front != NULL)
    {
        char *top = dequeue(q);
        if (strcmp(top, dest) == 0)
        {
            free(q);
            return graph->visited[top[0] - 'A'];
        }
        Node *curr = graph->adjList[top[0] - 'A'];
        while (curr != NULL)
        {
            if (graph->visited[curr->name[0] - 'A'] == 0)
            {
                graph->visited[curr->name[0] - 'A'] = graph->visited[top[0] - 'A'] + 1;
                strcpy(graph->parent[curr->name[0] - 'A'], top);
                enqueue(q, curr->name);
            }
            curr = curr->next;
        }
    }
    free(q);
    return -1;
}

void printPath(Graph *graph, char *src, char *dest)
{
    if (strcmp(src, dest) == 0)
    {
        return;
    }
    printPath(graph, graph->parent[src[0] - 'A'], dest);
    printf("%s %s\n", graph->parent[src[0] - 'A'], src);
}

int main()
{
    int n;
    int primera = 0;
    while (scanf("%d", &n) != EOF)
    {
        Graph *graph = createGraph();
        char s1[MAX_LENGTH], s2[MAX_LENGTH], start[MAX_LENGTH], end[MAX_LENGTH];
        for (int i = 0; i < n; ++i)
        {
            scanf("%s %s", s1, s2);
            addEdge(graph, s1, s2);
        }
        scanf("%s %s", start, end);
        if (primera)
           // printf("\n");
        primera = 1;
        int result = bfs(graph, start, end);
        if (result != -1)
        {
            printPath(graph, end, start);
        }
        else
        {
            printf("No route\n");
        }
        for (int i = 0; i < MAX_NODES; i++)
        {
            if (graph->adjList[i] != NULL)
            {
                Node *temp = graph->adjList[i];
                while (temp != NULL)
                {
                    Node *prev = temp;
                    temp = temp->next;
                    free(prev);
                }
            }
        }
        free(graph);
    }
    return 0;
}
