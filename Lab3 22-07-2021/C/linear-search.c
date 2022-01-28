#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int randomNumber()
{
    return rand() % (100) + 1;
}

int LinearSearch(int *arr, int n)
{
    int looped, key;
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        looped = n;
        key = randomNumber();
        if(arr[i] == key)
        {
            looped = i+1;
            break;
        }
    }
    return looped;
}

int main()
{
    FILE *outfile = fopen("LS_Data.csv", "w");
    int **vec, *arr;
    int n, num, testcases, *array_sizes;
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
    for(int i=0; i<array_sizes[0]; i++)
        printf("%d ", vec[0][i]);
    printf("\n");
    fprintf(outfile, "n,looped\n");
    for(int i=0; i<testcases; i++)
    {
        int looped = LinearSearch(vec[i], array_sizes[i]);
        fprintf(outfile, "%d,%d\n", array_sizes[i], looped);
    }
    return 0;
}