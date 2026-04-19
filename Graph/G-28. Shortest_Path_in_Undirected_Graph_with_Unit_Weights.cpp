#include<bits/stdc++.h>
using namespace std;

int main(){

    int V=4;
    vector<vector<int>> adj = {
        {3},
        {3},
        {},
        {0, 1}};
    vector<int> vis(V, 0), dist(V, 1e9);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int node = q.front();
        
        vis[node] = 1;
        q.pop();
        for(int u: adj[node]){
        if(!vis[u]){
        if(dist[u]>1+dist[node])
            dist[u] = 1+ dist[node];
        q.push(u);
        }
        }
    }
    for (int i = 0; i < V; i++)if(dist[i]==1e9)
            dist[i] = -1;

        return 0;
}