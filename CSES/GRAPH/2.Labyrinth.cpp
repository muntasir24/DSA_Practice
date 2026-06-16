#include <bits/stdc++.h>
using namespace std;
struct rowcol
{
    int row;
    int col;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<char>> path(n, vector<char>(m, '#'));
    queue<rowcol> q;
    rowcol start, end, node;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (adj[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<char> direction = {'U', 'R', 'D', 'L'};
    q.push(start);
    vis[start.row][start.col] = 1;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        int flag = 0;
        for (int i = 0; i < 4; i++)
        {
            int newX = node.row + dx[i];
            int newY = node.col + dy[i];
            if (newX >= 0 and newY >= 0 and newX < n and newY < m and !vis[newX][newY] and adj[newX][newY] != '#')
            {
                path[newX][newY] = direction[i];
                q.push({newX, newY});
                vis[newX][newY] = 1;
                if (newX == end.row and newY == end.col)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            break;
    }

    if (!vis[end.row][end.col])
    {
        cout << "NO\n";
        return 0;
    }

    string ans;
    node = end;
    while (!(node.row == start.row && node.col == start.col))
    {
        char move = path[node.row][node.col];
        ans.push_back(move);

        if (move == 'U')
            node.row++;
        else if (move == 'D')
            node.row--;
        else if (move == 'L')
            node.col++;
        else if (move == 'R')
            node.col--;
    }

    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.size() << '\n';
    cout << ans << '\n';

    return 0;
}