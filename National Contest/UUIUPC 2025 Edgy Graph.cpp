#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

int main(){
    ios::sync_with_stdio(false);
     cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector < vector<pair<int, int>>> adj(n+1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int mn = 1e9;
            for (auto node : adj[i])
            {
                mn = min(mn, node.second);
            }
            arr[i] = mn;
        }
        int flag = 1;
             for (int i = 1; i <= n; i++)
        {
            
            for (auto node : adj[i])
            {
                if(max(arr[i],arr[node.first])!=node.second){
                    flag = 0;
                    break;
                    
                }
            }
          
        }
        if(!flag){
            cout << -1 << endl;
            
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}