#include<iostream>
#include<vector>

using namespace std;

struct DP
{
    int **m;
    int **s;
    int n;
    DP(int arr_len)
    {
        n = arr_len;
        m = new int*[n];
        s = new int*[n];
        for(int i=0; i<n; i++)
        {
            m[i] = new int[n];
            s[i] = new int[n];
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                m[i][j] = -1;
                s[i][j] = 0;
            }
        cout<<"Constructor Sucess\n";
    }
}*dp;
 
int MatrixChainOrder(vector<int> M, int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT32_MAX, min_k;
    int count;
    if(dp->m[i][j] != -1)
        return dp->m[i][j];
    for(int k=i; k<j; k++)
    {
        count = MatrixChainOrder(M, i, k) + 
                MatrixChainOrder(M, k+1, j) +
                M[i-1]*M[k]*M[j];
        if(count<min)
        {
            min = count;
            min_k = k;
        }
        dp->m[i][j] = min;
        dp->s[i][j] = min_k;
    }
    return min;
}
 
int main()
{
    vector<int> M;
    int arr[] = {3, 2, 4, 5, 2};
    int n = sizeof(arr)/sizeof(*arr);
    dp = new DP(n);
    for(int i=0; i<n; i++)
        M.push_back(arr[i]);
    cout<<"Min Operations: "<<MatrixChainOrder(M, 1, n-1)<<'\n';
    cout<<"S-Table\n";
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
            cout<<dp->s[i][j]<<" ";
        cout<<'\n';
    }
    for(int i=n-1; i>=2; i--)
    {
        cout<<"(";
        for(int j=1; j<=dp->s[1][i]; j++)
            printf("%c", 64+j);
        cout<<")";
        for(int j=dp->s[1][i]+1; j<n; j++)
            printf("%c", 64+j);
        cout<<'\n';
    }
}