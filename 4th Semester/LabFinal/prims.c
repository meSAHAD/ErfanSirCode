#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX], parent[MAX], key[MAX], n, visited[MAX];

int minKey() {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void primMST() {
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey();
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Edges in Minimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d : %d\n", parent[i], i, graph[parent[i]][i]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST();

    return 0;
}

