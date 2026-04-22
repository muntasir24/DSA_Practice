#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}};

    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    if (grid[0][0] == 0)
    {
        pq.push({1, {0, 0}});
        dis[0][0] = 1;
    }

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        if (r == grid.size() - 1 and c == grid.size() - 1)
            break;
        pq.pop();
        for (int i = 0; i < 8; i++)
        {
            int newX = r + dx[i];
            int newY = c + dy[i];
            if (newX >= 0 and newX < grid.size() and newY >= 0 and newY < grid.size())
            {
                if (wt + 1 < dis[newX][newY] and grid[newX][newY] == 0)
                {
                    pq.push({wt + 1, {newX, newY}});
                    dis[newX][newY] = 1 + wt;
                }
            }
        }
    }
    cout << (dis[grid.size() - 1][grid.size() - 1] == INT_MAX ? -1 : dis[grid.size() - 1][grid.size() - 1]) << endl;
}