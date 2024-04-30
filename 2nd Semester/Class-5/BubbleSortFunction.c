#include <stdio.h>
void bubble_sort(int sort[], int n)
{
  int c, d, t;
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (sort[d] > sort[d+1])
      {
        t         = sort[d];
        sort[d]   = sort[d+1];
        sort[d+1] = t;
      }
    }
  }
}

int main()
{
  freopen("eb.txt", "r", stdin);
  int array[100], n, c, d, swap;
  scanf("%d", &n);
  for (c = 0; c < n; c++) scanf("%d", &array[c]);

  bubble_sort(array, n);

  printf("Sorted list in ascending order:\n");

  for ( c = 0 ; c < n ; c++ ) printf("%d ", array[c]);
  return 0;
}

