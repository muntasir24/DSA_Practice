#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>> &dist)
{
    int n = dist.size();
    for (int k = 0; k <n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][k]!=1e8 and dist[k][j]!=1e8){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

}

int main()
{
    vector<vector<int>> dist = {
        {0, 4, 100000000, 5, 100000000},
        {100000000, 0, 1, 100000000, 6},
        {2, 100000000, 0, 3, 100000000},
        {100000000, 100000000, 1, 0, 2},
        {1, 100000000, 100000000, 4, 0}};

    floydWarshall(dist);
    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist.size(); j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}