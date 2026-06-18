#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &color, bool &impossible)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            if (color[node] == 1)
            {
                color[child] = 2;
            }
            else
            {
                color[child] = 1;
            }
            dfs(child, adj, vis, color, impossible);
        }
        if (color[child] == color[node])
        {
            impossible = true;
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1), ans(n + 1);
    bool impossible = false;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans[i] = 1;
            dfs(i, adj, vis, ans, impossible);
        }
    }
    if (impossible)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}