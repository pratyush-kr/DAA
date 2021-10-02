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
 
int MatrixChainOrder(vector<int> M)
{
    DP dp(M.size());
    int n = M.size();
    for(int g=0; g<n; g++)
    {
        cout<<"Loop1\n";
        for(int i=0, j=g; j<n; j++, i++)
        {
            cout<<"Loop2\n";
            if(g == 0)
                dp.memo[i][j] = 0;
            else if(g = 1)
                dp.memo[i][j] = M[i]*M[j]*M[j+1];
            else
            {
                int min = INT32_MAX;
                for(int k=i; k<j; k++)
                {
                    cout<<"Loop3\n";
                    int lc = dp.memo[i][k];
                    int rc = dp.memo[k+1][j];
                    int mc = M[i]*M[j+1]*M[k+1];
                    int tc = lc+rc+mc;
                    min = (tc<min)? tc:min;
                }
                dp.memo[i][j] = min;
            }
        }
    }
    return dp.memo[0][dp.n-1];
}
 
int main()
{
    vector<int> M;
    for(int i=0; i<6; i++)
        M.push_back(10*(i+1));
    cout<<MatrixChainOrder(M);
}