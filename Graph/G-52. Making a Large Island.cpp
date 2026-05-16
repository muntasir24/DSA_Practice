#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
    vector<int> parent;
    vector<int> size;

public:
    Disjoint(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUlParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUlParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if (ulp_u == ulp_v)
            return;
        else if (size[ulp_u] > size[ulp_v])
        {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        else
        {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }
    int getSize(int node)
    {
        return size[findUlParent(node)];
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};
    int n = grid.size();
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    Disjoint ds(n * n);
    int chk = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                chk++;
                continue;
            }
            for (int k = 0; k < 4; k++)
            {
                int newX = dx[k] + i;
                int newY = dy[k] + j;
                int u = i * n + j;
                if (newX >= 0 and newX < n and newY >= 0 and newY < n)
                {
                    if (grid[newX][newY] == 1)
                    {
                        int v = newX * n + newY;
                        ds.unionBySize(u, v);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            set<int> st;
            if (grid[i][j] == 1)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int newX = dx[k] + i;
                int newY = dy[k] + j;
                if (newX >= 0 and newX < n and newY >= 0 and newY < n)
                {

                    if (grid[newX][newY] == 1)
                    {
                        int x = newX * n + newY;
                        st.insert(ds.findUlParent(x));
                    }
                }
            }
            int sizeTotal = 1;
            for (auto u : st)
            {
                sizeTotal += ds.getSize(u);
            }
            ans = max(ans, sizeTotal);
        }
    }
    cout << (chk == n * n ? 1 : (chk == 0 ? n * n : ans)) << endl;

    return 0;
}