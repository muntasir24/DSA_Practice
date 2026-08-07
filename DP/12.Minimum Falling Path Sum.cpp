#include <bits/stdc++.h>
using namespace std;

int f(int n, int m, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &v)
{
    if (j < 0 or j >= m or i >= n)
        return 1e5;
    if (i == n - 1)
        return v[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = f(n, m, i + 1, j, dp, v);
    int ld = f(n, m, i + 1, j - 1, dp, v);
    int rd = f(n, m, i + 1, j + 1, dp, v);

    return dp[i][j] = v[i][j] + min(down, min(rd, ld));
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m)), dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = 1e5, ld = 1e5, rd = 1e5;
            if (j - 1 >= 0)
                ld = dp[i - 1][j - 1];
            up = dp[i - 1][j];
            if (j + 1 < n )
                rd = dp[i-1][j + 1];
            dp[i][j] = matrix[i][j] + min(up, min(rd, ld));
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << dp[n-1][i] << " ";
    }

    return 0;
}