#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v>>w;
        adj[u].push_back({v, w});

    }
    vector<ll> dist(n + 1, 1e18);
    dist[1] = 0ll;
    pq.push({0ll, 1});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        ll wt = x.first;
        ll node = x.second;
        if (wt > dist[node])
            continue;
        for (auto child : adj[node])
        {
            ll cost = child.second;
            if (dist[child.first] > wt + cost)
            {
                dist[child.first] = wt + cost;
                pq.push({wt + cost, child.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}