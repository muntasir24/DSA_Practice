#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> adj1 = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}};
        
        vector<vector<int>> adj(7);
        
    vector<int> indegree(7, 0);
    for (int i = 0; i < 7; i++){
   for(auto u: adj1[i])
       {
           adj[u].push_back(i);
           indegree[i]++;
       }
    }
    // for (int i = 0; i < 6; i++)
    // {
    //     for(auto u:adj[i])
    //         cout << u << " ";
    //     cout << endl;
    // }
   
        queue<int> q;
    for (int i = 0; i < 7; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto ch : adj[node])
        {
            indegree[ch]--;
            if (indegree[ch] == 0)
                q.push(ch);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto u : ans)
        cout << u << endl;

    return 0;
}