#include<bits/stdc++.h>
using namespace std;


bool dfs(int node,int parent,int &startNode,int &endNode,vector<int>&vis,vector<int>&par,vector<vector<int>>&adj){
    vis[node] = 1;
    
    for(auto child:adj[node]){
        if (!vis[child]){
            par[child] = node;
            if (dfs(child, node, startNode, endNode, vis, par, adj))
            {
                return true;
            }
        }
        else if(parent!=child){
            startNode = child;
            endNode = node;
            return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0),par(n+1,0),cycle;
    for (int i = 0; i <m; i++)
    {
        int u, v;
        cin >> u >> v;
    
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int startNode, endNode,flag=0;
    for (int i = 1; i <= n; i++)
    {
      if(!vis[i] and dfs(i,i,startNode,endNode,vis,par,adj)){
          flag = 1;
          break;
      }
    }
    if(!flag){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cycle.push_back(startNode);
    while (endNode != startNode){
        cycle.push_back(endNode);
        endNode = par[endNode];
    }
    cycle.push_back(endNode);
    cout << cycle.size() << endl;
    for (auto u : cycle)
        cout << u << " ";
    cout << endl;

    return 0;
}