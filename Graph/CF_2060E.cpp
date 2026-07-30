#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
public:
    vector<int> parent;
    vector<int> size;
    Disjoint(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUlP(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUlP(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUlP(u);
        int ulp_v = findUlP(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m1, m2, u, v;
        cin >> n >> m1 >> m2;
        vector<pair<int, int>> v1(m1), v2(m2);
        for (int i = 0; i < m1; i++)
        {
            cin >> v1[i].first >> v1[i].second;
        }
        for (int i = 0; i < m2; i++)
        {
            cin >> v2[i].first >> v2[i].second;
        }
        Disjoint ds1(n), ds2(n);
        for (int i = 0; i < m2; i++)
        {
            ds2.unionBySize(v2[i].first, v2[i].second);
        }
        int ans = 0;
        for (int i = 0; i < m1; i++)
        {
            u = v1[i].first;
            v = v1[i].second;
            if (ds2.findUlP(u) == ds2.findUlP(v))
            {
                ds1.unionBySize(u, v);
            }
            else
            {
                ans++;
            }
        }
        set<int> st1, st2;
        for (int i = 1; i <= n; i++)
        {
            st1.insert(ds1.findUlP(i));
            st2.insert(ds2.findUlP(i));
        }
      
        cout << (ans + (st1.size() - st2.size())) << endl;
    }

    return 0;
}
