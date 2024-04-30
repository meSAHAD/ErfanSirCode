#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 101
#define MAX_COLS 101

typedef struct Pair
{
    int first;
    int second;
} Pair;

typedef struct QueueNode
{
    Pair data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

char v[MAX_ROWS][MAX_COLS];

int m, n;

int fx[] = {0, 0, 1, 1, -1, -1, 1, -1}; // Direction Array
int fy[] = {1, -1, 1, -1, 1, -1, 0, 0}; // Direction Array

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, Pair data)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
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

Pair dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty!\n");
        exit(1);
    }
    QueueNode *temp = q->front;
    Pair data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void bfs(int x, int y)
{
    Queue *q = createQueue();
    enqueue(q, (Pair){x, y});
    while (q->front != NULL)
    {
        Pair top = dequeue(q);
        for (int i = 0; i < 8; i++)
        {
            int f = top.first + fx[i];
            int s = top.second + fy[i];
            if ((f >= 0 && f < m) && (s >= 0 && s < n) && v[f][s] == '@')
            {
                v[f][s] = '*';
                enqueue(q, (Pair){f, s});
            }
        }
    }
    free(q);
}

int main()
{
    while (scanf("%d %d", &m, &n) == 2)
    {
        if (m == 0 && n == 0)
            break;
        for (int i = 0; i < m; i++)
        {
            scanf("%s", v[i]);
        }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == '@')
                {
                    count++;
                    bfs(i, j);
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
