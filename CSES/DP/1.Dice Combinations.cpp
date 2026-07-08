#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll fun(ll curr, ll target, vector<ll> &dp)
{
    if (curr == target)
        return 1;
    if (curr > target)
        return 0;
    if (dp[curr] != -1)
        return dp[curr];
    ll ans = 0;
    for (ll i = 1; i <= 6; i++)
    {
        ans = (ans + fun(curr + i, target, dp)) % mod;
    }
    return dp[curr] = ans;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 7, 0);
    // cout << fun(0, n, dp) << endl;
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= 6; j++)
        {
            dp[i] = (dp[i] + dp[i + j]) % mod;
        }
    }
    cout << dp[0] << endl;

    return 0;
}