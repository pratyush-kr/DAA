#include<stdio.h>

int main()
{
    int n;
    printf("n: ");
    scanf(" %d", &n);
    int arr[n];
    printf("Array: ");
    for(int i=0; i<n; i++)
        scanf(" %d", &arr[i]);
    int product = 1;
    for(int i=0; i<n; i++)
        product = product*arr[i];
    for(int i=0; i<n; i++)
        printf("%d ", product/arr[i]);
    printf("\n");
}