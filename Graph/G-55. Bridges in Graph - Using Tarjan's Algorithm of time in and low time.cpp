// 1192. Critical Connections in a Network

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&ans,int node,int parent,int Time,vector<vector<int>> &adj, vector<int>& disc, vector<int>& low, vector<int>& vis){
    vis[node] = 1;
    disc[node] = low[node] = ++Time;

    for(auto child:adj[node]){
    if(child!=parent and !vis[child]){
        dfs(ans,child, node, Time, adj, disc, low, vis);
    }
    else if(child!=parent and vis[child]){
        low[node] = min(low[node], low[child]);

    }
    }
    // done processing
    low[parent] = min(low[parent], low[node]);
    if(disc[parent]<low[node]){
        ans.push_back({parent, node});
    }
}

int main(){
    int n = 12;
    vector<vector<int>> adj = {
        {},          // 0 (unused)
        {2, 4},      // Node 1
        {1, 3},      // Node 2
        {2, 4},      // Node 3
        {1, 3, 5},   // Node 4
        {4, 6},      // Node 5
        {5, 7, 9},   // Node 6
        {6, 8},      // Node 7
        {7, 9, 10},  // Node 8
        {6, 8},      // Node 9
        {8, 11, 12}, // Node 10
        {10, 12},    // Node 11
        {10, 11}     // Node 12
    };

 vector<int>disc(adj.size()),low(adj.size()),vis(adj.size(),0);
 vector<vector<int>> ans;
 for (int i = 1; i < adj.size(); i++)
 {
    if(!vis[i]) dfs(ans,i, 1, 0, adj, disc, low, vis);
 }
 for(auto u:ans)
     cout << u[0] << " " << u[1] << endl;

    return 0;
}
