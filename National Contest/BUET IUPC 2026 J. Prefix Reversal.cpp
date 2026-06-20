#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> v(n+1);
        ll ans=0;
        vector<pair<ll, int>> vp;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            ans += i * v[i];
        }
        vp.push_back({ans, 1});
        ll initial = v[1];
        for (ll i = 1; i < n; i++)
        {
            ans = ans + (initial - i * v[i + 1]);
            vp.push_back({ans, i + 1});
            initial += v[i + 1];
        }
        sort(vp.begin(), vp.end());
        for (auto u : vp)
            cout <<  u.second << " ";
        cout << endl;
    }

    return 0;
}