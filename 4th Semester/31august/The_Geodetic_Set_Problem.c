// status: wrong answer

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f

int d[40+5][40+5];
int rec[40+5][40+5];
int isgeo[40+5];
int set[40+5];

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }

    memset(rec, 0, sizeof(rec));
    char s[500];

    for(int i = 1; i <= n; i++) {
        scanf(" %[^\n]", s); // Read full line
        char *token = strtok(s, " ");
        while(token != NULL) {
            int j = atoi(token);
            d[i][j] = 1;
            token = strtok(NULL, " ");
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(d[i][j] == d[i][k] + d[k][j]) {
                    rec[i][j] = 1;
                }
            }
        }
    }

    int cas;
    scanf("%d", &cas);
    getchar(); // Consume newline
    
    for(int i = 0; i < cas; i++) {
        memset(set, 0, sizeof(set));
        memset(isgeo, 0, sizeof(isgeo));

        fgets(s, sizeof(s), stdin);
        char *token = strtok(s, " ");
        while(token != NULL) {
            int j = atoi(token);
            set[j] = 1;
            token = strtok(NULL, " ");
        }

        int ans = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(set[i] && set[j]) {
                    for(int k = 1; k <= n; k++) {
                        if(rec[i][j]) {
                            isgeo[k] = 1;
                        }
                    }
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(set[i] && !isgeo[i]) {
                ans = 0;
            }
        }

        if(ans) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
