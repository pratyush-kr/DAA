#include<stdio.h>

int main()
{
    int n, key;
    printf("n: ");
    scanf(" %d", &n);
    int arr[n];
    int diff[n];
    printf("Array: ");
    for(int i=0; i<n; i++)
        scanf(" %d", &arr[i]);
    printf("key: ");
    scanf(" %d", &key);
    int found = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(arr[i]*arr[i] + arr[j]*arr[j] == key)
            {
                printf("i: %d\nj: %d\n", i, j);
                found = 1;
                break;
            }
            if(found)
                break;
        }
    if(!found)
        printf("No val avilable\n");

}