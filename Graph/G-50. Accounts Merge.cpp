#include<bits/stdc++.h>
using namespace std;

struct ps
{
    int parent, size;
};

class Disjoint{
    public:
    vector<int> parent;
    vector<int> size;
    Disjoint(int n){
        size.resize(n, 1);
        parent.resize(n);
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
        if(ulp_u==ulp_v)
            return;
        else if(size[ulp_v]>size[ulp_u]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v];
        }
    }
};

int main(){
    vector<vector<string>> accounts = {
      {"John","johnsmith@mail.com","john_newyork@mail.com"},
      {"John","johnsmith@mail.com","john00@mail.com"},
      {"Mary","mary@mail.com"},
      {"John","johnnybravo@mail.com"}
    };

    unordered_map<string, int> mp;
    unordered_map<int, string> mpInverse;
    unordered_map<string, string> emailtoName;
    string email;
    int n=0;
    for (auto u : accounts)
    {
        for (int i = 1; i < u.size(); i++)
        {
            email = u[i];
            if(mp.find(email)==mp.end()){
                mp[email] = n;
                mpInverse[n] = email;
                emailtoName[email] = u[0];
                n++;
            }
        }
    }
    Disjoint ds(n);
    
    for(auto acc:accounts){
        int parent, maxsize = 0;
        for (int i = 1; i < acc.size(); i++)
        {
            int pr = ds.findUlParent(mp[acc[i]]);
            int node_size = ds.size[pr];
            maxsize = max(maxsize, node_size);
            if(maxsize==node_size)
                parent = pr;
        }
        int u = parent;
        int v;
        for (int i = 1; i < acc.size(); i++)
        {
             v = mp[acc[i]];
            ds.unionBySize(u, v);
        }
        // cout <<ds.size[u]<< endl;
    }
    unordered_map<int, int> mailIndex;
    int anscnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(i==ds.parent[i]){
            mailIndex[i] = anscnt;
            anscnt++;
        }
    }
    // for(auto x:mailIndex)
    //     cout << x.first << " " << x.second << endl;
    vector<vector<string>> ans(anscnt);
    for (int i = 0; i < n; i++)
    {
        string mail = mpInverse[i];
        int prnt = ds.findUlParent(i);
        int idx = mailIndex[prnt];
        ans[idx].push_back(mail);
    }
    for(auto u:ans){
        if(u.empty())
            continue;
        sort(u.begin(), u.end());
        u.insert(u.begin(),emailtoName[u[0]]);
        for (auto x : u)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
