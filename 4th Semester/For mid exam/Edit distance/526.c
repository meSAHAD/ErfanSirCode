#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 1005

char a[MAX_LENGTH];
char b[MAX_LENGTH];
int offset, steps;

void print(int i, int j, int dp[][MAX_LENGTH]) {
    if (i == 0 && j == 0)
        return;
    else if (i != 0 && j != 0 && a[i - 1] == b[j - 1]) {
        print(i - 1, j - 1, dp);
    } else if (j != 0 && dp[i][j] == dp[i][j - 1] + 1) {
        print(i, j - 1, dp);
        offset++;
        printf("%d Insert %d,%c\n", ++steps, i + offset, b[j - 1]);
    } else if (i != 0 && dp[i][j] == dp[i - 1][j] + 1) {
        print(i - 1, j, dp);
        printf("%d Delete %d\n", ++steps, i + offset);
        offset--;
    } else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
        print(i - 1, j - 1, dp);
        printf("%d Replace %d,%c\n", ++steps, i + offset, b[j - 1]);
    }
}

int main() {
    bool printed = false;
    while (fgets(a, MAX_LENGTH, stdin)) {
        if (printed)
            printf("\n");
        printed = true;
        fgets(b, MAX_LENGTH, stdin);
        a[strcspn(a, "\n")] = '\0';
        b[strcspn(b, "\n")] = '\0';
        int dp[MAX_LENGTH][MAX_LENGTH] = {{0}};
        int len_a = strlen(a);
        int len_b = strlen(b);

        for (int i = 0; i <= len_b; i++)
            dp[0][i] = i;

        for (int i = 0; i < len_a; i++) {
            dp[i + 1][0] = i + 1;
            for (int j = 0; j < len_b; j++) {
                if (a[i] == b[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = ((dp[i][j] < dp[i][j + 1]) ? dp[i][j] : dp[i][j + 1]);
                    dp[i + 1][j + 1] = ((dp[i + 1][j + 1] < dp[i + 1][j]) ? dp[i + 1][j + 1] : dp[i + 1][j]);
                    dp[i + 1][j + 1]++;
                }
            }
        }
        printf("%d\n", dp[len_a][len_b]);
        offset = steps = 0;
        print(len_a, len_b, dp);
    }
    return 0;
}

