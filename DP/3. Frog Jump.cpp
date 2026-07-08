#include <bits/stdc++.h>
using namespace std;

int fun(int n, int size, vector<int> &dp, vector<int> &v)
{
    if (n >= size)
        return 0;

    if (dp[n] != -1)
        return dp[n];
    int a = fun(n + 1, size, dp, v) + (n + 1 >= size ? 1e5 : abs(v[n + 1] - v[n]));
    int b = fun(n + 2, size, dp, v) + (n + 2 >= size ? 1e5 : abs(v[n + 2] - v[n]));

    return dp[n] = (min(a, b) == 1e5 ? 0 : min(a, b));
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n), dp(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    fun(0, n, dp, v);
    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }

    return 0;
}