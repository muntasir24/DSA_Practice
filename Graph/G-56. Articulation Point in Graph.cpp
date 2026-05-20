#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int &Time,int parent,vector<vector<int>> &adj, vector<int> &vis, vector<int> &art, vector<int> &disc, vector<int> &low) {
    int child_cnt = 0;
    vis[node] = 1;
    low[node] = disc[node] = ++Time;
    // cout <<"disc and low for " <<node<<" values "<< disc[node] << " " <<  low[node] << endl;
    for(auto child:adj[node]){
        // cout <<"node & child     " << node << " -> " << child <<" "<<parent<< endl;
        
        
        if (child == parent)
        {
            continue;
        }
     if(!vis[child]){
        //  cout << " dfs " << child << endl;
         dfs(child, Time, node, adj, vis, art, disc, low);
        //  cout << "backtracked !! "<<node << endl;
        //   cout <<"backtracked before "<< "disc and low for " <<node<<" values "<< disc[node] << " " << low[node]  << endl;
         low[node] = min(low[child], low[node]);
        //   cout <<"backtracked after "<< "disc and low for " <<node<<" values "<< disc[node] << " " << low[node]  << endl;
        //   cout <<"updated disc and low for " <<node<<" values "<< disc[node] << " " << low[node]  << endl;
         if(parent!=-1 and disc[node]<=low[child]){
            //  cout << "art point " << node << endl;
             art[node] = 1;
         }
         if(parent==-1)
             child_cnt++;
     }
     else{
         low[node] = min(low[node], disc[child]);
        //   cout <<"updated disc and low for " <<node<<" values "<< disc[node] << " " << low[node]  << endl;
     }
    }

    if(parent==-1 and child_cnt>1){
        art[node] = 1;
    }
};

int main(){
    int n = 7;
    vector<vector<int>> adj(n);
    
  
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {0, 3}, {2, 3},
        {2, 4}, {2, 5}, {4, 6}, {5, 6}
    };

    for(auto it : edges) {
        int u = it.first;
        int v = it.second;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    int timer = 0;
    vector<int> vis(n, 0), art(n, 0), low(n), disc(n);
    dfs(0,timer, -1, adj, vis, art, disc, low);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(art[i])
            ans.push_back(i);
    }
    

    return 0;
}
