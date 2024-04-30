#include <stdio.h>

int main()
{
    int n, count = 0;
    while (scanf("%d", &n) != EOF)
    {
        int arr[n];
        int i,j;
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for ( i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    count++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", count);
        count = 0;
    }
    return 0;
}
