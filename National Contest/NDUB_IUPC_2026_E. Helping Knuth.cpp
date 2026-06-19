#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> used(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] != -1) used[v[i]] = true;
    }
    
    vector<int> unused;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) unused.push_back(i);
    }
    
    if (n > 0 && v[0] == -1 && !unused.empty()) {
        v[0] = unused.back();
        unused.pop_back();
    }
    
    if (n > 1 && v[n - 1] == -1 && !unused.empty()) {
        v[n - 1] = unused.front();
        unused.erase(unused.begin());
    }
    
    for (int i = 0; i < n; i++)
    {
        if (v[i] == -1) {
            v[i] = unused.back();
            unused.pop_back();
        }
        cout << v[i] << " ";
    }
    cout << endl;
    }

    return 0;
}