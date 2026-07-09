#include <bits/stdc++.h>
using namespace std;
struct id
{
    int r, c, l;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dc[4] = {'U', 'R', 'D', 'L'};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    vector<vector<int>> vis1(n, vector<int>(m, 0));
    vector<int> vis(n * m, 1e9);
  vector<pair<int,char>> parent(n*m, pair<int,char>(-1, '0'));
    queue<id> q, qa;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            vis1[i][j] = 0;
            if (adj[i][j] == 'M')
            {
                q.push({i, j, 0});
                int uloc = (m * i + j);
                vis[uloc] = 0;
                vis1[i][j] = 0;
            }
            if (adj[i][j] == 'A')
                qa.push({i, j, 0});
        }
    }

    while (!q.empty())
    {
        auto loc = q.front();
        q.pop();
        int x = loc.r;
        int y = loc.c;
        int level = loc.l;

        for (int i = 0; i < 4; i++)
        {
            int newX = dx[i] + x;
            int newY = dy[i] + y;
            int uloc = (m * newX + newY);
            if (newX >= 0 and newY >= 0 and newX < n and newY < m and vis[uloc] == 1e9 and adj[newX][newY] == '.')
            {
                q.push({newX, newY, level + 1});
                vis[uloc] = min(vis[uloc], level + 1);
            }
        }
    }
    int flag = 0,stloc;
    while (!qa.empty())
    {
        auto loc = qa.front();
        qa.pop();
        int x = loc.r;
        int y = loc.c;
        int level = loc.l;
         int ploc = (m * x + y);
        if (x == n - 1 or y == m - 1 or x == 0 or y == 0)
        {
            flag = 1;
            stloc = ploc;
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int newX = dx[i] + x;
            int newY = dy[i] + y;
           
            int uloc = (m * newX + newY);
            if (newX >= 0 and newY >= 0 and newX < n and newY < m and !vis1[newX][newY] and adj[newX][newY] == '.')
            {
                int val = vis[uloc];
                vis1[newX][newY] = 1;
                if (level + 1 < val)
                {
                    qa.push({newX, newY, level + 1});
                    parent[uloc] = {ploc, dc[i]};
                }
            }
        }
    }
    if(!flag){
        cout << "NO" << endl;
        return 0;
    }
    string ans;
    while (stloc != -1)
    {
        int idx = parent[stloc].first;
        ans += parent[stloc].second;
        stloc = idx;
    }

    cout << "YES" << endl;
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}