#include <bits/stdc++.h>
using namespace std;

int count(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];
    dp[n] = count(n - 1, dp);
    return dp[n] += count(n - 2, dp);
}

int main()
{

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    count(n, dp);
   for (int i = 0; i <=n; i++)
   {
       cout << dp[i] << endl;
   }
}