#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<int>> obstacleGrid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> obstacleGrid[i][j];
        }
    }

    // return f(n, m, dp, 0, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 and j == 0) or obstacleGrid[i][j]==1)
                continue;
            

            int up = 0, left = 0;
            if (i - 1 >= 0)
                up = dp[i - 1][j];
            if (j - 1 >= 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}