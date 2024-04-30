#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in the input array
int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort
void countingSort(int arr[], int n)
{
    int max = findMax(arr, n);

    // Create a count array and initialize it to 0
    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Count the occurrences of each element in the input array
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    countingSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
