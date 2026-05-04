#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent,size;
    public:
    // Constructor: A special function that runs automatically when an object is created.
    // Why use it? It prepares the initial state. When we say `DisjointSet ds(7)`, 
    // it automatically resizes the arrays and sets everyone as their own boss!
    DisjointSet(int n){
        rank.resize(n + 1, 0); // Initially, all ranks are 0
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i; // Initially, everyone is their own boss
            size[i] = 1;
        }
    }
    
    // Function to find the Ultimate Boss with Path Compression
    int findUlParent(int node){
        if(node==parent[node]){
            return node; // Base case: Found the boss
        }
        // Path Compression: find ultimate parent and assign it directly
        // BUG FIXED: Called findUlParent on parent[node], not node!
        return parent[node] = findUlParent(parent[node]);
    }
    
    // Function to merge two sets by Rank
    void unionByRank(int u, int v){
        // BUG FIXED: Must find ULTIMATE parent, not immediate parent
        int ulp_u = findUlParent(u); //ultimate parent of u
        int ulp_v = findUlParent(v); //ultimate parent of v
        if(ulp_u==ulp_v){
            return; // Already in the same component, doing nothing
        }
        
        // Attach smaller rank tree under larger rank tree
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            // Ranks are equal, attach one under another 
            parent[ulp_v] = ulp_u;
            // BUG FIXED: Increase the rank of the NEW boss (ulp_u)
            rank[ulp_u]++;
        }
    }

    void unionBysize(int u,int v){
        int ulp_u = findUlParent(u); //ultimate parent of u
        int ulp_v = findUlParent(v); //ultimate parent of v
        if(ulp_u==ulp_v){
            return;
        }
        if (size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


int main(){

    DisjointSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    // //if 3 & 7 belong to same component
    // if(ds.findUlParent(3)==ds.findUlParent(7)){
    //     cout << "Belong to same component" << endl;
    // }
    // else {
    //     cout << "Different Component" << endl;
    // }
    // ds.unionByRank(3, 7);

    ds.unionBysize(1, 2);
    ds.unionBysize(2, 3);
    ds.unionBysize(4, 5);
    ds.unionBysize(6, 7);
    ds.unionBysize(5, 6);
    //if 3 & 7 belong to same component
   
    ds.unionBysize(3, 7);
     if(ds.findUlParent(3)==ds.findUlParent(7)){
        cout << "Belong to same component" << endl;
    }
    else {
        cout << "Different Component" << endl;
    }
   

    return 0;
}