#include<iostream>
#include<map>

using namespace std;

struct Strings
{
    char *A;
    char *B;
    int m;
    int n;
    int **memo;
    Strings(string A, string B)
    {
        this->A = &A[0];
        this->B = &B[0];
        m = A.size();
        n = B.size();
        memo = new int*[m];
        for(int i=0; i<m; i++)
            memo[i] = new int[n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                memo[i][j] = -1;
    }
    int lcs(int , int);
};

int Strings::lcs(int i, int j)
{

}

int main()
{
    string A, B;
    A = "stone";
    B = "longest";
    printf("A: %s\n", &A[0]);
    printf("B: %s\n", &B[0]);
    Strings x(A, B);
    x.lcs(x.m, x.n);
    for(int i=0; i<x.m; i++)
    {
        for(int j=0; j<x.n; j++)
        {
            int l = x.memo[i][j];
            cout<<((l == -1)?l+1:l)<<" ";
        }
        cout<<'\n';
    }
    return 0;
}