#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V = 6;

    vector<int> adj[V] = {
        {},     // 0
        {},     // 1
        {3},    // 2
        {1},    // 3
        {0, 1}, // 4
        {2, 0}  // 5
    };
    vector<int> vis(V, 0), order, indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto u : adj[i])
            indegree[u]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (auto ch : adj[node])
        {
            indegree[ch]--;
            if (indegree[ch] == 0)
                q.push(ch);
        }
    }
    bool cycle = false;
    for(auto u:indegree)if(u>0)
            cycle = true;
    cout << cycle << endl;

    return 0;
}