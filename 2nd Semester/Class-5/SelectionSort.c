#include<stdio.h>
int main()
{
    int n; scanf("%d",&n);
    int arr[n],temp;
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    for(int i=0; i<n-1; i++)//O(n^2);
    {
        int min_index=i;
        {
            for(int j=i+1; j<n; j++)
            {
                if(arr[j]<arr[min_index])
                {
                    min_index=j;
                }

            }
            if(min_index!=i)
            {

                temp=arr[i];
                arr[i]=arr[min_index];
                arr[min_index]=temp;
            }

        }
    }
    for(int i=0; i<n; i++)
    {

        printf("%d ",arr[i]);
    }
}

