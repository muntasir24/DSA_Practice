#include<bits/stdc++.h>
using namespace std;



int main(){

    int n = 7, m = 8;
    vector<vector<pair<int, int>>> adj={
        {{1, 2}},
        {{3, 1}},
        {{3, 3}},
        {},
        {{0, 3}, {2, 1}},
        {{4, 1}},
        {{4, 2}, {5, 3}}
    };
    vector<int> dist(n, 1e9), topo,vis(n,0);
    
    auto dfs = [&](auto&& self, int node) -> void {
        vis[node] = 1;
        for(auto u: adj[node]){
            if(!vis[u.first])
                self(self, u.first);
        }
        topo.push_back(node);
    };

     for (int i = 0; i < n; i++)
     {
        if(!vis[i])
            dfs(dfs, i);
     }
     reverse(topo.begin(), topo.end());

     int srcVertex = 6;
     dist[srcVertex]=0;
    for (int i = 0; i < n; i++)
    {
        int node = topo[i];
        if (dist[node] != 1e9) {
            for(auto u: adj[node]){
                if(dist[u.first]>dist[node]+u.second)
                    dist[u.first] = dist[node] + u.second;
            }
        }
    }
    
    for(auto u: dist) {
        if (u == 1e9) cout << "-1 ";
        else cout << u << " ";
    }
    cout << endl;

     return 0;
}