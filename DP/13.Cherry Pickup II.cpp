#include <bits/stdc++.h>
using namespace std;

int f(int n, int m, int i, int j1, int j2, vector<vector<int>> &v, vector<vector<vector<int>>> &dp)
{

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;
    

    if (i == n - 1)
    {
        if (j1 == j2)
            return v[i][j1];
        else
            return v[i][j1] + v[i][j2];
    }
    if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];

    int mx = 0;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            if (j1 == j2)
                mx = max(mx, v[i][j1] + f(n, m, i + 1, j1 + dj1, j2 + dj2, v, dp));
            else
                mx = max(mx, v[i][j1] + v[i][j2] + f(n, m, i + 1, j1 + dj1, j2 + dj2, v, dp));
        }
    }

    return dp[i][j1][j2]=mx;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
   for (int j1 = 0; j1 <m; j1++)
   {
    for (int j2 = 0; j2 <m; j2++)
    {
        if (j1 == j2)
            dp[n - 1][j1][j2] = grid[n-1][j2];
        else
            dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
   }
   for (int i = n-2; i >=0; i--)
   {
       for (int j1 = 0; j1 < m; j1++)
       {
           for (int j2 = 0; j2 < m; j2++)
           {
               int mx = 0;
               for (int dj1 = -1; dj1 <= 1; dj1++)
               {
                   for (int dj2 = -1; dj2 <= 1; dj2++)
                   {
                    if(j1+dj1<0 || j2+dj2<0 || j1+dj1>=m || j2+dj2>=m)
                        continue;

                    if (j1 == j2)
                        mx = max(mx, grid[i][j1] + dp[i + 1][j1 + dj1] [j2 + dj2]);
                    else
                        mx = max(mx, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2]);
                   }
               }
               dp[i][j1][j2] = mx;
           }
       }
   }
   cout << dp[0][0][m - 1] << endl;

   return 0;
}