#include<stdio.h>
#include<string.h>

int main() {
    char s[85];
    int n;
    int flag;

    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        int i;
        for (i = 1; i <= strlen(s); i++) {
            if (strlen(s) % i == 0) {
                flag = 1;
                int j, k;
                for (j = 0; j < i; j++) {
                    for (k = 1; k < strlen(s) / i; k++) {
                        if (s[j] != s[k * i + j]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 0) break;
                }
                if (flag == 1) {
                    printf("%d\n", i);
                    if (n) printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}
