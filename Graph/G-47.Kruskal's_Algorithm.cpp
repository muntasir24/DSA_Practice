#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
vector<int> size, parent;

    public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i = 1; i <=n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node==parent[node])
            return node;

        return parent[node]=findUParent(parent[node]);
    }
    void unionSize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        else if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int main(){

    DisjointSet ds(6);
    
    // {weight, {u, v}}
    vector<pair<int, pair<int, int>>> edges = {
        {1, {1, 4}},
        {2, {1, 2}},
        {3, {2, 3}},
        {3, {2, 4}},
        {4, {1, 5}},
        {5, {3, 4}},
        {7, {2, 6}},
        {8, {3, 6}},
        {9, {4, 5}}
    };
    sort(edges.begin(), edges.end());
    int mst = 0;
    for (auto x : edges)
    {
        int wt = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if(ds.findUParent(u)!=ds.findUParent(v))
        mst += wt;
    ds.unionSize(u, v);
    }
    cout << mst << endl;

    return 0;
}