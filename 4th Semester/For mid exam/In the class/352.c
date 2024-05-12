#include <stdio.h>

#define MAX_SIZE 100

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int image[MAX_SIZE][MAX_SIZE], int x, int y, int size)
{
    image[x][y] = 0;
    int i;
    for (i = 0; i < 8; ++i)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= size || ty < 0 || ty >= size)
            continue;
        if (image[tx][ty] == 1)
            dfs(image, tx, ty, size);
    }
}

int main()
{
    int Case = 1, n;
    while (scanf("%d", &n) != EOF)
    {
        getchar();

        char s[MAX_SIZE];
        int image[MAX_SIZE][MAX_SIZE];
        int x;
        for (x = 0; x < n; ++x)
        {
            fgets(s, sizeof(s), stdin);
            int y;
            for (y = 0; y < n; ++y)
                image[x][y] = s[y] - '0';
        }

        int nCC = 0;
        int z;
        for (x = 0; x < n; ++x)

            for (z = 0; z < n; ++z)
                if (image[x][z] == 1)
                {
                    ++nCC;
                    dfs(image, x, z, n);
                }

        printf("Image number %d contains %d war eagles.\n", Case++, nCC);
    }
    return 0;
}
