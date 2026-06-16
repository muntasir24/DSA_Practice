#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &adj)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 and newX < n and newY >= 0 and newY < m and !vis[newX][newY] and adj[newX][newY] == '.')
        {
            dfs(newX, newY, n, m, vis, adj);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(adj[i][j]=='.' and !vis[i][j]){
                ans++;
                dfs(i, j, n, m, vis, adj);
            }
        }
    }
    cout << ans << endl;
    return 0;
}