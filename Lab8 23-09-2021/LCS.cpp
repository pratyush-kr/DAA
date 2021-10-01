#include<iostream>
#include<map>

using namespace std;

struct LCS
{
    char *A;
    char *B;
    int m;
    int n;
    int **memo;
    LCS(string A, string B)
    {
        this->A = &A[0];
        this->B = &B[0];
        m = A.size();
        n = B.size();
        memo = new int*[m];
        for(int i=0; i<n; i++)
            memo[i] = new int[n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                memo[i][j] = 0;
    }
};

int lcs_len(LCS x, int m, int n)
{
    if(m == 0 || n == 0)
        return 0;
    if(x.memo[m-1][n-1] != 0)
        return x.memo[m-1][n-1];
    if(x.A[m-1] == x.B[n-1])
    {
        x.memo[m-1][n-1] = 1 + lcs_len(x, m-1, n-1);
        return x.memo[m-1][n-1];
    }
    else
    {
        x.memo[m-1][n-1] = max(lcs_len(x, m-1, n), lcs_len(x, m, n-1));
        return x.memo[m-1][n-1];
    }
    return 0;
}

int main()
{
    string A, B;
    printf("A: ");
    cin>>A;
    printf("B: ");
    cin>>B;
    LCS x(A, B);
    lcs_len(x, x.m, x.n);
    for(int i=0; i<x.m; i++)
    {
        for(int j=0; j<x.n; j++)
            cout<<x.memo[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}