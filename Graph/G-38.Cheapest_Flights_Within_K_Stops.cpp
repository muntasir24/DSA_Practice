#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> flights = {
        {0, 2, 50},
        {0, 1, 20},
        {1, 2, 20},
        {2, 3, 10},
        {1, 3, 50},
        {1, 5, 100},
        {3, 4, 10},
        {4, 5, 10},
        {3, 5, 10}};
    queue<pair<int,pair<int,int>>> q;
    int n = 6, src = 0, dst = 5, k = 2;

    vector<vector<pair<int, int>>> adj(n);
    for (auto &flight : flights)
    {
        adj[flight[0]].push_back({flight[1], flight[2]});
    }

    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    
    q.push({0,{src,0}});
    while (!q.empty())
    {
        int wt = q.front().first;
        int node = q.front().second.first;
        int level = q.front().second.second;
        // cout << node << " " << wt << " " << level << endl;
        
        if (level > k)
            break;
        q.pop();
        for (auto u : adj[node])
        {
            int child = u.first;
            int cost = u.second;
            // cout << child << " " << cost + wt << endl;
            if (cost + wt < dis[child])
            {
                q.push({cost + wt, {child,level+1}});
                dis[child] = cost + wt;
            }
        }
    }
    cout << dis[dst] << endl;

    return 0;
}