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
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
                if(arr[i] + arr[j] + arr[k] == key)
                {
                    printf("i: %d\nj: %d\nk: %d\n", i, j, k);
                    found = 1;
                    break;
                }
                if(found)
                    break;
        }
        if(found)
            break;
    }
    if(!found)
        printf("No val avilable\n");

}