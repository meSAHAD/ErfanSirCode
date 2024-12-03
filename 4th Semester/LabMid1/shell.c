#include <stdio.h>

void shellSort(int array[], int n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i++)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

int main()
{
    freopen("shellinnput.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int data[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("Original Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    shellSort(data, n);
    printf("Shell Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}