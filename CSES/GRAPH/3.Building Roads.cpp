#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;

    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (i > 1)
                ans.push_back({1, i});
            dfs(i, adj, vis);
        }
    }
    cout << ans.size() << endl;
    for (auto u : ans)
    {
        cout << u.first << " " << u.second << " ";
    }
    cout << endl;

    return 0;
}