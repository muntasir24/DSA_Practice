#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> &order, vector<int> adj[], vector<int>&vis)
{

    vis[u] = 1;
    for (auto ch : adj[u])
    {
        if (!vis[ch])
            dfs(ch, order, adj, vis);
    }

    order.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vis(6, 0), order;
    vector<int> adj[6] = {
        {},     // 0
        {},     // 1
        {3},    // 2
        {1},    // 3
        {0, 1}, // 4
        {2, 0}  // 5
    };
    for (int i = 0; i < 6; i++)
    {
        if (!vis[i])
            dfs(i, order, adj, vis);
    }
    reverse(order.begin(), order.end());
    for(auto o :order)
        cout << o << " ";

    return 0;
}