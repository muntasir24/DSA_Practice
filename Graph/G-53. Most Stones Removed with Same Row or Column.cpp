#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    public :
    vector<int> parent;
    vector<int> size;
    Disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
        for (int i = 0; i <n; i++)
        {
            parent[i] = i;
        }
    }
    int findUlParent(int node){
        if(node==parent[node])
            return node;
        return parent[node] = findUlParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        else if(size[ulp_u]>size[ulp_v]){
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        else{
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }
    int getAns(int totalStones){
        int connectedComponents = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if(parent[i] == i) {
                connectedComponents++;
            }
        }
        return totalStones - connectedComponents;
    }
};

int main(){
    vector<vector<int>> stones = {
        {1, 0},
        {3, 4},
        {0, 0},
        {4, 5},
        {1, 5},
        {2, 0},
        {5, 3},
        {5, 2}};

    int n = stones.size();
    map<pair<char, int> ,int> mp;
    int cnt = 0;
    for (auto cor : stones)
    {
        int x = cor[0];
        int y = cor[1];
        if(mp.find({'L',x})==mp.end()){
            mp[{'L', x}] = cnt;
            cnt++;
        }
        if(mp.find({'R',y})==mp.end()){
            mp[{'R', y}] = cnt;
            cnt++;
        }
    }
    // for(auto u:mp)
    //     cout << u.first.first << " " << u.first.second << "  " << u.second << endl;
    Disjoint ds(cnt);
    for(auto cor:stones){
        int x = cor[0];
        int y = cor[1];
        int u = mp[{'L', x}];
        int v = mp[{'R', y}];
        ds.unionBySize(u, v);
    }
    // ds.findUlParent(8);
    // ds.findUlParent(4);
    // ds.findUlParent(5);
    // for (int i = 0; i < cnt; i++)
    // {
    //     cout << i << " " << ds.parent[i] << endl;
    // }
    cout << ds.getAns(n) << endl;
    return 0;
}