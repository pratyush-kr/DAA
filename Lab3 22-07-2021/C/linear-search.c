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
    FILE *outfile = fopen("Data.csv", "w");
    int **vec, *arr;
    int n, num, m, *array_sizes;
    printf("n: ");
    scanf(" %d", &n);
    vec = (int**)malloc(sizeof(int*)*n);
    array_sizes = (int*)malloc(sizeof(int)*n);
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        m = randomNumber();
        arr = (int*)malloc(sizeof(int)*m);
        for(int j=0; j<m; j++)
        {
            num = randomNumber();
            arr[j] = num;
        }
        vec[i] = arr;
        array_sizes[i] = m;
    }
    fprintf(outfile, "n,looped\n");
    char size[5], loop[5];
    for(int i=0; i<n; i++)
    {
        int looped = LinearSearch(vec[i], array_sizes[i]);
        sprintf(loop, "%d", looped);
        sprintf(size, "%d", array_sizes[i]);
        fprintf(outfile, "%s,%s\n", size, loop);
    }
    return 0;
}