#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct array array;

struct array
{
    int *arr;
    int n;
};

int euclid(int, int);
int consInteger(int, int);
int sieve(int, int);
char* compare(int, int);

int main()
{
    int a, b;
    char command[25];
    while(1)
    {
        printf("command: ");
        scanf(" %s", command);
        if(!strcmp(command, "euclid"))
        {
            scanf("%d", &a);
            scanf("%d", &b);
            printf("GCD(%d, %d) = %d\n", a, b, euclid(a, b));
        }
        else if(!strcmp(command, "consecutive"))
        {
            scanf(" %d", &a);
            scanf(" %d", &b);
            printf("GCD(%d, %d) = %d\n", a, b, consInteger(a, b));
        }
        else if(!strcmp(command, "legacy"))
        {
            scanf(" %d", &a);
            scanf(" %d", &b);
            printf("GCD(%d, %d) = %d\n", a, b, sieve(a, b));
        }
        else if(!strcmp(command, "exit"))
            break;
        else if(!strcmp(command, "compare"))
        {
            scanf(" %d", &a);
            scanf(" %d", &b);
            printf("%s\n", compare(a, b));
        }
    }
    return 0;
}

int euclid(int a, int b)
{
    if(a == 0)
        return b;
    return euclid(b % a, a);
}

int consInteger(int a, int b)
{
    int t = (a<b)? a:b;
    while(t > 0)
    {
        if(a%t == 0)
            if(b%t == 0)
                return t;
        t--;
    }
}

array SieveOfEratosthenes(int n)
{
    array primefactor;
    primefactor.arr = (int *)malloc(sizeof(int) * (n+1));
    primefactor.n = 0;
    int prime[n+1];

    for(int i=0; i<=n; i++)
        prime[i] = 1;
  
    for(int p=2; p*p<=n; p++)
        if (prime[p] == 1)
            for (int i=p*2; i<=n; i += p)
                prime[i] = 0;
    int i=0;
    for (int p=2; p<=n; p++)
       if (prime[p] && n%p == 0)
        primefactor.arr[i++] = p,
        primefactor.n++;
    return primefactor;
}

int sieve(int a, int b)
{
    array pfa = SieveOfEratosthenes(a);
    array pfb = SieveOfEratosthenes(b);
    array g, s;
    g = (pfa.n > pfb.n)? pfa:pfb;
    s = (pfa.n < pfb.n)? pfa:pfb;
    for(int i=g.n-1; i>=0; i--)
        for(int j=s.n-1; j>=0; j--)
            if(g.arr[i] == s.arr[j])
                return g.arr[i];
}

char* compare(int a, int b)
{
    clock_t start, end;
    double f1, f2, f3;
    start = clock();
    euclid(a, b);
    end = clock();
    f1 = ((double)(end - start))/CLOCKS_PER_SEC;
    start = clock();
    consInteger(a, b);
    end = clock();
    f2 = ((double)(end - start))/CLOCKS_PER_SEC;
    start = clock();
    sieve(a, b);
    end = clock();
    f3 = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time taken by Euclidian Algo = %f\n", f1*10000);
    printf("Time taken by Consecutive Integer = %f\n", f2*10000);
    printf("Time taken by Legacy = %f\n", f3*10000);
    if(f1 <= f2 && f1 <= f3)
        return "Euclid is faster";
    else if(f2 <= f1 && f2 <= f3)
        return "Consecutive integer is faster";
    return "Legacy is faster";
}