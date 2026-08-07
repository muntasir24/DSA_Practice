#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct con
{
    int u, v, w;
};

int main()
{

    int n, m, u, v, w;
    cin >> n >> m;
    vector<con> edges(m + 1);
    vector<vector<int>> adj(n + 1);
    vector<ll> dist(n + 1, -1e18);
    dist[1] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        adj[edges[i].u].push_back(edges[i].v);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[edges[j].u] + edges[j].w > dist[edges[j].v])
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }
    // for (int i = 1; i <=n; i++)
    // {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;

    set<int> cycle_nodes;
    for (int j = 0; j < m; j++)
    {
        if (dist[edges[j].u] + edges[j].w > dist[edges[j].v])
        {
            dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            cycle_nodes.insert(edges[j].v);
           
        }
    }
   

    // 1 to cycles
    vector<int> vis(n + 1, 0);
    queue<int> q, q_cycle;
    q.push(1);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        if (cycle_nodes.count(u))
        {

            q_cycle.push(u);
        }
        for (auto child : adj[u])
        {
            q.push(child);
        }
    }
  

    vis.assign(n + 1, 0);
    int flag = 0;
    while (!q_cycle.empty())
    {
        u = q_cycle.front();
        q_cycle.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        if (u == n)
            flag = 1;
        for (auto child : adj[u])
            q_cycle.push(child);
    }
    cout << (flag ? -1 : dist[n]) << endl;

    return 0;
}
