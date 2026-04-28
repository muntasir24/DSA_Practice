#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3, 4, 65};
    int start = 7, end = 66175;
    const int mod = 1e5;
    queue<int> q;
    vector<int> dis(mod, -1);
    q.push(start);
    dis[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if(node==end)
            break;
        for (int i = 0; i < arr.size(); i++)
        {
            int next = (arr[i] * node) % mod;
            if (dis[next] == -1)
            {
                dis[next] = dis[node] + 1;
                q.push(next);
            }
        }
    }
    cout << dis[end] << endl;

    return 0;
}