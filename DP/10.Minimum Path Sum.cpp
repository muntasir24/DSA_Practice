#include<bits/stdc++.h>
using namespace std;

int f(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&v,int i,int j){
    if(i>=n or j>=m)
        return 1e5;
    if(i==n-1 and j==m-1)
        return v[i][j];

   if(dp[i][j]!=-1)
       return dp[i][j];
   return dp[i][j] = v[i][j] + min(f(n, m, dp, v, i + 1, j), f(n, m, dp, v, i, j + 1));
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m)), dp(n, vector<int>(m,-1));
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = grid[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i==0 and j==0)
                continue;
            int left = 1e5, up = 1e5;
            if (i - 1 >=0){
                up = dp[i - 1][j];
            }
            if(j-1>=0){
                left = dp[i][j - 1];
            }
            dp[i][j] = grid[i][j] + min(left, up);
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}