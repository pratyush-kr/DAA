#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int randomNumber()
{
    return (rand() % 10000) + 1;
}

int insertionSort(int *array, int n)
{
    int looped = 0;
    for(int step = 1; step < n; step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
            looped++;
        }
        array[j + 1] = key;
    }
    return looped;
}

int main()
{
    FILE *outfile = fopen("IS_Data.csv", "w");
    int **vec, *array_sizes;
    int n, num, testcases;
    int *arr;
    printf("TestCases: ");
    scanf(" %d", &testcases);
    vec = (int**)malloc(sizeof(int*)*testcases);
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
        vec[i] = arr;
        array_sizes[i] = n;
    }
    fprintf(outfile, "n,looped\n");
    for(int i=0; i<testcases; i++)
    {
        int looped = insertionSort(vec[i], array_sizes[i]);
        fprintf(outfile, "%d,%d\n", array_sizes[i], looped);
    }
    return 0;
}