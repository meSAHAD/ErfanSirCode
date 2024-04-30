#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_ROWS 101
#define MAX_COLS 101

typedef struct Pair
{
    int first;
    int second;
} Pair;

char v[MAX_ROWS][MAX_COLS];
int m, n;

int fx[] = {0, 0, 1, 1, -1, -1, 1, -1};
int fy[] = {1, -1, 1, -1, 1, -1, 0, 0};

int front = -1, rear = -1;
Pair queue[MAX_ROWS * MAX_COLS - 1];
bool isFull()
{
    return (rear == MAX_ROWS * MAX_COLS - 1);
}

bool isEmpty()
{
    return (front == -1 || front > rear);
}

void enqueue(Pair data)
{
    if (isFull())
    {
        printf("Queue is full");
        exit(1);
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = data;
}

Pair dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty");
        exit(1);
    }
    Pair data = queue[front];
    front++;
    return data;
}

void BFS(int x, int y)
{
    enqueue((Pair){x, y});
    while (!isEmpty())
    {
        Pair top = dequeue();
        int i;
        for (i = 0; i < 8; i++)
        {
            int f = top.first + fx[i];
            int s = top.second + fy[i];
            if ((f >= 0 && f < m) && (s >= 0 && s < n) && (v[f][s] == '@'))
            {
                v[f][s] = '*';
                enqueue((Pair){f, s});
            }
        }
    }
}

int main()
{
    while (scanf("%d%d", &m, &n) == 2)
    {
        if (m == 0 && n == 0)
            break;

        int i, j;
        for (i = 0; i < m; i++)
        {

            scanf(" %c", &v[i]);
        }
        int count=0;
        for (i = 0; i < m; i++){
            for(j=0;j<n;j++){
                if(v[i][j]=='@'){
                    count++;
                    BFS(i,j);
                }
            }
        }
        printf("%d\n",count);
    }

    return 0;
}