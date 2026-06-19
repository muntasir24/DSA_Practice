#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll k;
    cin >> k;

    // ll n = (k * 2) - 1;
    // ll tot = ((n * (n + 1)) / 2) - ((n / 2) * ((n / 2) + 1));
    // cout << ((tot / 2) + 1) / 2 << endl;
    //  Mathematically simplified formula that avoids overflow
    unsigned long long ans = (unsigned long long)(k / 2) * ((k + 1) / 2);
    cout << ans << "\n";
    }

    return 0;
}