#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &i);
    }

    int sum = 0;

    for(int i=0; i<n; i++)
    {
        sum = sum + i;
    }

    int avg = sum/n;

    printf("%d %d", &sum, &avg);

    for(int i=0; i<n; i++)
    {
        printf("%d \n", &i);
    }
    return 0;
}

