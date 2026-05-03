#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> &edges)
{
    
    vector<vector<pair<int,int>>> adj(V);
    for (auto it : edges)
    {
        // it = {u, v, weight}
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    int sum = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    
    pq.push({0, {0, -1}});
    vector<int> vis(V, 0);
    // vector<pair<int, int>> mstEdges;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        // cout << wt << " " << node << " " << parent << endl;
        if (!vis[node])
        {
            vis[node] = 1;
            sum += wt;
        }else
            continue;

        for(auto u:adj[node]){
            int ch = u.first;
            int cost = u.second;
            if (!vis[ch])
            {
                // cout << ch << " " << cost << endl;
                pq.push({cost, {ch, node}});
            }
        }
    }

    // cout << "\n Weight: " << sum << endl;
    return sum;
}

int main()
{
    /*

     0 --(1)-- 1
     |         |
    (2)       (1)
     |         |
     +--- 2 ---+
          |
         (5)
          |
          3 --(4)-- 4

    */

    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 1}, // weight 1
        {1, 2, 1}, // weight 1
        {0, 2, 2}, // <-- Tempting Edge with min weight 2! It will form a cycle.
        {2, 3, 5},
        {3, 4, 4}};

    spanningTree(V, edges);

    return 0;
}