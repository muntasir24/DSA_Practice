#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    vector<vector<pair<long long, long long>>> adj(n);

    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    const long long mod = 1e9 + 7;
    vector<long long> dis(n, LONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    dis[0] = 0;
    pq.push({0, 0});
    vector<long long> ways(n, 0);
    ways[0] = 1;
    while (!pq.empty())
    {
        long long node = pq.top().second;
        long long wt = pq.top().first;
        pq.pop();

        for (auto u : adj[node])
        {
            long long cost = u.second;
            long long child = u.first;
            if (cost + wt == dis[child])
            {
                ways[child] = (ways[child] + ways[node]) % mod;
            }
            else if (cost + wt < dis[child])
            {
                pq.push({cost + wt, child});
                dis[child] = cost + wt;
                ways[child] = ways[node];
            }
        }
    }
    cout << ways[n - 1] << endl;
    return 0;
}