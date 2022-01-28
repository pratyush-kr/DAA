#include<stdio.h>

int main()
{
    int n, max = 0;
    printf("n: ");
    scanf(" %d", &n);
    int arr[n];
    printf("Array: ");
    for(int i=0; i<n; i++)
        scanf(" %d", &arr[i]);
    int product = 1;
    for(int i=0; i<n; i++)
        max = (arr[i] > arr[max])? i : max;
        printf("%d ", max);
    printf("\n");

}