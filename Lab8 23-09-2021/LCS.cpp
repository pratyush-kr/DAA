#include<iostream>
#include<map>

using namespace std;

struct Strings
{
    char *A, *B;
    int n, m;
    Strings(string A, string B)
    {
        this->A = &A[0];
        this->B = &B[0];
        n = A.size();
        m = B.size();
    }
    char* lcs(int , int);
};

char* Strings::lcs(int n, int m)
{
    int memo[n+1][m+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0)
                memo[i][j] = 0;
            else if(A[i-1] == B[j-1])
                memo[i][j] = 1+memo[i-1][j-1];
            else
                memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
        }
        
    }
    int i=n, j=m;
}

int main()
{
    string A, B;
    A = "stone";
    B = "longest";
    printf("A: %s\n", &A[0]);
    printf("B: %s\n", &B[0]);
    Strings x(A, B);
    cout<<x.lcs(x.n, x.m)<<'\n';
    return 0;
}