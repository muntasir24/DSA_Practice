#include <bits/stdc++.h>
using namespace std;

int dfs(int node,int parent, vector<vector<int>> &adj, vector<int> &v, int &ans)
{

    for (auto child : adj[node])
    {
        if(child!=parent){
            v[node] ^= dfs(child, node, adj, v, ans);
            // cout << " loop " << node << " " << v[node] << " ans : " << ans << endl;
        }
    }

    if (v[node])
        ans++;

    // cout <<" outside loop "<< node << " " << v[node]<<" ans : "<<ans << endl;
    return v[node];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            if(v[i])
                cnt++;
        }
       
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        if (cnt % 2)
        {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        dfs(1,1, adj, v, ans);
        cout << ans << endl;
    }

    return 0;
}