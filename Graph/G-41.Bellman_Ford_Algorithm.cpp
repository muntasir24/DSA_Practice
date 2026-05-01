#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int V = 5;
    int src = 0;
    vector<int> dis(V, 1e8);
    dis[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto x : edges)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            if (dis[u] != 1e8 and dis[u] + wt < dis[v])
            {
                dis[v] = dis[u] + wt;
            }
        }
    }

    for (auto x : edges)
    {
        int u = x[0];
        int v = x[1];
        int wt = x[2];
        if (dis[u] != 1e8 and dis[u] + wt < dis[v])
        {
            // return {-1};
        }
    }

    for (auto u : dis)
        cout << u << " ";

    return 0;
}