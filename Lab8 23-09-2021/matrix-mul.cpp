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
    int min = INT32_MAX;
    int count;
    if(dp->m[i][j] != -1)
        return dp->m[i][j];
    for(int k=i; k<j; k++)
    {
        count = MatrixChainOrder(M, i, k) + 
                MatrixChainOrder(M, k+1, j) +
                M[i-1]*M[k]*M[j];
        min = (count<min)? count:min;
        dp->m[i][j] = min;
        dp->s[i][j] = k;
    }
    return min;
}
 
int main()
{
    vector<int> M;
    int arr[] = {3, 2, 4, 2, 5};
    int n = sizeof(arr)/sizeof(*arr);
    dp = new DP(n);
    for(int i=0; i<n; i++)
        M.push_back(arr[i]);
    cout<<MatrixChainOrder(M, 1, n-1)<<'\n';
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
            cout<<dp->s[i][j]<<" ";
        cout<<'\n';
    }
}