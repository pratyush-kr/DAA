#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int func_call = 0;

int randomNumber()
{
    return rand() % 10000 + 1;
}

void merge(int *arr, const int l, const int m , const int r)
{
    int *array = (int*)malloc(sizeof(int)*(r-l+1));
    int i=l, j=m+1, z=0;
    while(i <= m && j <= r)
    {
        func_call++;
        if(arr[i] <= arr[j])
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

int main()
{
    int testcases, n, num;
    printf("TestCases: ");
    scanf("%d", &testcases);
    int **arrays, *arr, *array_sizes;
    arrays = (int**)malloc(sizeof(int*)*testcases);
    array_sizes = (int*)malloc(sizeof(int)*testcases);
    srand(time(0));
    for(int i=0; i<testcases; i++)
    {
        n = randomNumber();
        arr = (int*)malloc(sizeof(int)*n);
        for(int j=0; j<n; j++)
        {
            num = randomNumber();
            arr[j] = num;
        }
        arrays[i] = arr;
        array_sizes[i] = n;
    }
    int time_taken;
    FILE *outfile = fopen("MS_data.csv", "w");
    fprintf(outfile, "n,looped\n");
    for(int i=0; i<testcases; i++)
    {
        func_call = 0;
        merge_sort(arrays[i], 0, array_sizes[i]-1);
        time_taken = func_call;
        fprintf(outfile, "%d,%d\n", array_sizes[i]-1, time_taken);
    }
    return 0;
}