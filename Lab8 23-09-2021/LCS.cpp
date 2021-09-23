#include<iostream>

int updateLcs(std::string A, std::string B, int **lcs, int m, int n)
{
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(A[i] == B[j])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = (lcs[i][j-1] > lcs[i-1][j])? lcs[i][j-1]:lcs[i-1][j];
        }
    }
}

std::string findlcs(std::string A, std::string B, int **lcs, int m, int n)
{
    std::string str = "";
    for(int i=m-1; i>0; i--)
    {
        for(int j=n-1; j>0; j--)
        {
            if(lcs[i][j] == 0)
                return str;
            if(lcs[i-1][j-1] + 1 == lcs[i][j] && lcs[i][j-1] != lcs[i][j])
            {
                str += A[i-1];
                i--;
            }
        }
    }
}

int main()
{
    std::string A, B;
    printf("A: ");
    std::cin>>A;
    printf("B: ");
    std::cin>>B;
    int m = A.length()+1;
    int n = B.length()+1;
    int **lcs;
    lcs = new int*[m];
    for(int i=0; i<m; i++)
        lcs[i] = new int[n];
    for(int i=0; i<m; i++)
        lcs[i][0] = 0;
    for(int i=0; i<n; i++)
        lcs[0][i] = 0;
    updateLcs(A, B, lcs, m, n);
    std::cout<<findlcs(A, B, lcs, m, n)<<'\n';
    return 0;
}