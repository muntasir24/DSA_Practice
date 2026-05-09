#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    vector<int> size, parent;
public:
    Disjoint(int n){
        size.resize(n,1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUparent(parent[node]);
    }
    int unionBySize(int u,int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u==ulp_v)
            return 1;
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
        {
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }
        return 0;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

    Disjoint ds(n);
    int cnt = 0;
    for (auto x : connections)
    {
        int u = x[0];
        int v = x[1];
        cnt += ds.unionBySize(u, v);
        
    }
    int component_cnt=0;
    for (int i = 0; i < n; i++)
    {
        if (i == ds.findUparent(i))
            component_cnt++;
    }
    if(cnt>=component_cnt-1)
        cout << component_cnt << endl;

    return 0;
}