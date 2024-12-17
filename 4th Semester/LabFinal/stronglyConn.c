#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], reverseGraph[MAX][MAX], visited[MAX], n;

void DFS(int graph[MAX][MAX], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i);
        }
    }
}

void transposeGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            reverseGraph[i][j] = graph[j][i];
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("Strongly Connected Components (Kosaraju's Algorithm):\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(graph, i);
            printf("\n");
        }
    }

    transposeGraph();

    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("SCC after transpose graph DFS:\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(reverseGraph, i);
            printf("\n");
        }
    }

    return 0;
}

