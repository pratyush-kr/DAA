#include<stdio.h>

int main()
{
    int n;
    printf("n: ");
    scanf(" %d", &n);
    int arr[n], max = -100, hash_map[n], num;
    printf("Array: ");
    for(int i=0; i<n; i++)
    {
        hash_map[i] = 0;
        scanf(" %d", &arr[i]);
    }
    //map the array
    for(int i=0; i<n; i++)
        hash_map[arr[i]%n]++;
    //find the index with max in hash_map
    max = 0;
    for(int i=0; i<n; i++)
        max = (hash_map[i] >= hash_map[max])? i : max;
    //finding the num
    for(int i=0; i<n; i++)
    {
        if(max == arr[i]%n)
        {
            num = arr[i];
            break;
        }
    }
    int index = 0;
    //finding the index
    for(int i=0; i<n; i++)
    {
        if(arr[i] == num)
            index = i;
    }
    printf("Index of Number with max duplicates: %d\n", index);
    return 0;
}