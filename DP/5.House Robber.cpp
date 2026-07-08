#include <bits/stdc++.h>
using namespace std;

int fun(int n, int size, vector<int> &v, vector<int> &dp)
{
    if (n >= size)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int mx = 0;
    for (int i = n + 2; i < size; i++)
    {
        mx = max(fun(i, size, v, dp), mx);
    }

    return dp[n] = v[n] + mx;
}

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n), dp(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    fun(0, n, nums, dp);
    fun(1, n, nums, dp);
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    sort(dp.begin(), dp.end());
    

    return 0;
}