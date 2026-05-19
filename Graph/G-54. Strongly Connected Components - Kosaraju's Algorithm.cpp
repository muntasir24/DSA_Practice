#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj, int node,stack<int>&st, vector<int>&vis){
    vis[node] = 1;
    for(auto u:adj[node]){
        if(!vis[u])
            dfs(adj, u, st, vis);
    }
    st.push(node);
}
void dfs2(vector<vector<int>>&adj, int node, vector<int>&vis){
    vis[node] = 1;
    for(auto u:adj[node]){
        if(!vis[u])
            dfs2(adj, u, vis);
    }
  
}

int main(){

    vector<vector<int>> adj = {
        {1},       // 0
        {2},       // 1
        {0, 3},    // 2
        {4},       // 3
        {5, 7},    // 4
        {6},       // 5
        {4, 7},    // 6
        {}         // 7
    };

    stack<int> st;
    vector<int> vis(adj.size(), 0);
    int n = adj.size();
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(adj, i, st, vis);
    }
   
    vector<vector<int>> adjT(n);
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto v : adj[i])
        {
            adjT[v].push_back(i);
        }
    }
    int ans = 0;
    while (!st.empty())
    {
        int node = st.top();
         if(!vis[node]){
             dfs2(adjT, node, vis);
             ans++;
         }
        st.pop();
    }
    cout << ans << endl;

    return 0;
}