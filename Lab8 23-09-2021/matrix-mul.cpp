#include<iostream>
#include<vector>

using namespace std;

struct DP
{
    int **memo;
    int n;
    DP(int arr_len)
    {
        n = arr_len;
        memo = new int*[n];
        for(int i=0; i<n; i++)
            memo[i] = new int[n];
        cout<<"Constructor Sucess\n";
    }
};
 
int MatrixChainOrder(vector<int> M, int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT32_MAX;
    int count;
    for(int k=i; k<j; k++)
    {
        count = MatrixChainOrder(M, i, k) + 
                MatrixChainOrder(M, k+1, j) +
                M[i-1]*M[k]*M[j];
        min = (count<min)? count:min;
    }
    return min;
}
 
int main()
{
    vector<int> M;
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    for(int i=0; i<n; i++)
        M.push_back(arr[i]);
    cout<<MatrixChainOrder(M, 1, n-1)<<'\n';
}