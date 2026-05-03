#include<bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> adj(n, vector<int>(n,INT_MAX));
    for(auto u: edges){
        adj[u[0]][u[1]] = u[2];
        adj[u[1]][u[0]] = u[2];
    }

    vector<int> nodes(n);
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i <n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==j){
                    adj[i][j] = 0;
                }

                if(adj[i][k]!=INT_MAX and adj[k][j]!=INT_MAX ){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << adj[i][j] << " ";
            if(adj[i][j]<=distanceThreshold){
                nodes[i]++;
            }
        }
        mn = min(mn, nodes[i]);
    }
    for (int i = n-1; i >=0; i--)
    {
        if (nodes[i] == mn)
            return i;
    }
}


int main(){

    int n = 4;
    vector<vector<int>> edges = { { 0, 1, 3 }, { 1, 2, 1 }, { 1, 3, 4 }, { 2, 3, 1 } };

    int distanceThreshold = 4;

    cout << "The city is: " << findTheCity(n, edges, distanceThreshold) << endl;

    return 0;
}