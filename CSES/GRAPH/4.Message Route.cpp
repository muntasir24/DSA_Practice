#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1), vis(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    int found = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto u : adj[node])
        {
            if (!vis[u])
            {
                vis[u] = 1;
                q.push(u);
                parent[u] = node;
                if (u == n)
                {
                    found = 1;
                    break;
                }
            }
        }
        if (found)
            break;
    }
    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> ans;
    int ch = n;
    while (ch != 1)
    {
        ans.push_back(ch);
        ch = parent[ch];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto u : ans)
        cout << u << " ";
    cout << endl;

    return 0;
}