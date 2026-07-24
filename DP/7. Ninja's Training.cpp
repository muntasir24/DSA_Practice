#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(int n, vector<vector<int>> &v, vector<vector<int>> &dp, int idx)
{
    if (n == 0)
    {
        int mx = 0;
        for (int i = 0; i < 3; i++)
        {
            if (idx != i)
            {
                mx = max(v[n][i], mx);
            }
        }

        return mx;
    }
    // if(dp[n][idx]!=-1)
    //     return dp[n][idx];
    int mx = 0;
    for (int i = 0; i < 3; i++)
    {

        if (i != idx)
        {
            mx = max((v[n][i] + f(n - 1, v, dp, i)), mx);
        }
    }
    // cout << n << " " << idx << " " << mx << endl;
    return dp[n][idx] = mx;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> points[i][j];
            }
        }
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // memoization
        //  f(n - 1, points, dp, 3);
        //  cout << dp[n - 1][3] << endl;

        // tabulation

        dp[0][0] = points[0][0];
        dp[0][1] = points[0][1];
        dp[0][2] = points[0][2];
        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                int mx = 0;
                for (int k = 0; k < 3; k++)
                {
                    if (j != k)
                    {
                        mx = max(mx, dp[i - 1][k]);
                    }
                }
                dp[i][j] = points[i][j] + mx;
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        cout << max(dp[n - 1][0] ,max(dp[n - 1][1], dp[n - 1][2])) << endl;
    }

    return 0;
}