#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], stack[MAX], top = -1;

void topologicalSort(int v, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            topologicalSort(i, n);
        }
    }

    stack[++top] = v;
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (from to):\n");
    for (int i = 0; i < e; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from][to] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSort(i, n);
        }
    }

    printf("Topological Order:\n");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}

