#include<bits/stdc++.h>
using namespace std;
struct costpath
{
    long long node, cost;
};

int main(){
    long long n, m;
    cin >> n >> m;
    vector<vector<costpath>> adj(n+1);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    // for ( long long i = 1; i <=n; i++)
    // {
    //     for (auto x:adj[i])
    //         cout << x.node << " " << x.cost << endl;
    //     cout << "___" << endl;
    // }
    set<pair<long long,long long>> st;
    st.insert({0, 1});
    const long long INF = LLONG_MAX;
    vector<long long> dis(n + 1, INF);
    dis[1] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        long long node = it.second;
        long long wt = it.first;
         st.erase(st.begin());
    
        for(auto child :adj[node]){
            long long cost = child.cost;
            if(cost+wt<dis[child.node]){
                if(st.find({dis[child.node],child.node})!=st.end()){
                    st.erase({dis[child.node], child.node});
                }
                dis[child.node] = cost + wt;
                st.insert({wt+cost, child.node});
            }
        }
    }
    for (long long i = 1; i <= n;i++)
        cout << dis[i] << " ";
    cout << endl;

    return 0;
}