#include <stdio.h>
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[1000],n;
	freopen("eb.txt", "r", stdin);
	scanf("%d", &n);
    for (int c = 0; c < n; c++) scanf("%d", &arr[c]);
	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}

