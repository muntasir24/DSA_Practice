#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
private:
    int f(int n, int m, vector<vector<int>> &dp, int i, int j)
    {
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }
        else if (i >= n || j >= m)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        return dp[i][j] = f(n, m, dp, i + 1, j) + f(n, m, dp, i, j + 1);
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // return f(n, m, dp, 0, 0);
        dp[1][1] = 1;
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <=m; j++)
            {
                if (i == 1 and j == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    cout << sol.uniquePaths(3, 3) << endl;
    return 0;
}