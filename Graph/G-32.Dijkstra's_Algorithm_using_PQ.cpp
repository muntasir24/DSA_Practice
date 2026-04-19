#include<bits/stdc++.h>
using namespace std;

int main(){
    int src = 2,V=3;
    vector<vector<pair<int, int>>> adj = {
        {{1, 1}, {2, 6}},
        {{0, 1}, {2, 3}},
        {{1, 3}, {0, 6}}
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto child : adj[node])
        {
            int cost = child.second;
            if(wt+cost<dis[child.first])
                {
                    dis[child.first] = dis[node] + cost;
                    pq.push({ wt+ cost,child.first});
                }
        }
    }
    for(auto u: dis)
        cout << u << " ";
}