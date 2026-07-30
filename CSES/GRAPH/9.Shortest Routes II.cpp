#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main()
{

    ll n, m, q, u, v, w;
    cin >> n >> m >> q;
    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v],w);
        adj[v][u] = min(adj[u][v], w);
    }
    for (int i = 1; i <= n; i++)
    {
        adj[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> u >> v;
        cout << (adj[u][v] == INF ? -1 : adj[u][v]) << endl;
    }

    return 0;
}