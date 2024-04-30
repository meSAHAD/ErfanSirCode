#include <stdio.h>

void countingSort(int a[], int n)
{
    int output[10];
    int c[10];
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max) max = a[i];

    }

    for (int i = 0; i <= max; ++i) c[i] = 0;

    for (int i = 0; i < n; i++)    c[a[i]]++;

    for (int i = 1; i <= max; i++) c[i] += c[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    for (int i = 0; i < n; i++) a[i] = output[i];
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(array) / sizeof(array[0]);
    countingSort(array, n);
    printArray(array, n);
}
