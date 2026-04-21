#include<bits/stdc++.h>
using namespace std;

struct nodecost
{
    int node, cost;
};

int main(){
    int n = 5, m = 6;
    vector<array<int, 3>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };
    vector<vector<nodecost>> adj(n + 1);
    vector<int> dis(n+1, INT_MAX);
    vector<int> parent(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    parent[1] = 1;

    for (const auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }


    while(!pq.empty()){
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if(wt>dis[node])
            continue; //state entry

        for (auto child : adj[node])
        {
            int cost = child.cost;
            if(wt+cost<dis[child.node]){
                pq.push({wt + cost, child.node});
                parent[child.node] = node;
                dis[child.node] = wt + cost;
            }
        }
    }
    vector<int> path;
    path.push_back(n);
    int i = n;
    while(i!=1){
        int pathnode = parent[i];
        i = pathnode;
        path.push_back(pathnode);
    }
    reverse(path.begin(), path.end());
    for(auto u:path)
        cout << u << " ";

    return 0;
}