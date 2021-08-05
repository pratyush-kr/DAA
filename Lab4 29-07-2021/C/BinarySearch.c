#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int func_call = 0;

void merge(int *arr, const int l, const int m , const int r)
{
    int *array = (int*)malloc(sizeof(int)*(r-l+1));
    int i=l, j=m+1, z=0;
    while(i <= m && j <= r)
    {
        if(arr[i] < arr[j])
            array[z++] = arr[i++];
        else
            array[z++] = arr[j++];
    }
    while(i <= m)
        array[z++] = arr[i++];
    while(j <= r)
        array[z++] = arr[j++];
    for(int i=l; i<=r; i++)
        arr[i] = array[i - l];
}

void merge_sort(int *arr, const int l, const int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int randomNumber()
{
    return rand() % 100 + 1;
}

int binary_search(int *arr, int l, int r, int key)
{
    int mid;
    while(l<=r)
    {
        func_call++;
        mid = (l+r)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return binary_search(arr, l, mid-1, key);
        else if(arr[mid] < key)
            return binary_search(arr, mid+1, r, key);
    }
    return -1;
}

int main()
{
    int mp[1000];
    for(int j=0; j<1000; j++)
            mp[j] = 0;
    int testcases, n, num;
    printf("TestCases: ");
    scanf("%d", &testcases);
    int **arrays, *arr, *array_sizes;
    arrays = (int**)malloc(sizeof(int*)*testcases);
    array_sizes = (int*)malloc(sizeof(int)*testcases);
    srand(time(0));
    for(int i=0; i<testcases; i++)
    {
        int size = 0;
        n = randomNumber();
        arr = (int*)malloc(sizeof(int)*n);
        for(int j=0; j<n; j++)
        {
            num = randomNumber();
            if(mp[num] < 1)
            {
                arr[j] = num;
                size++;
            }
            mp[num]++;
        }
        n = size;
        arrays[i] = arr;
        array_sizes[i] = n;
        for(int j=0; j<1000; j++)
            mp[j] = 0;
    }
    int time_taken, key;
    FILE *outfile = fopen("BS_data.csv", "w");
    fprintf(outfile, "n,looped\n");
    for(int i=0; i<testcases; i++)
    {
        merge_sort(arr, 0, array_sizes[i]-1);
        func_call = 0;
        key = randomNumber();
        binary_search(arrays[i], 0, array_sizes[i], key);
        time_taken = func_call;
        fprintf(outfile, "%d,%d\n", array_sizes[i]-1, time_taken);
    }
    return 0;
}