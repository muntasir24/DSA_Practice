#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}};

    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    pq.push({0, {0, 0}});
    dis[0][0] = 0;
    int dx[] = {-1, 0, 1, 0}; // Row change: Up, Right, Down, Left
    int dy[] = {0, 1, 0, -1}; // Col change: Up, Right, Down, Left
    while(!pq.empty()){
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        int wt = pq.top().first;
        if(r==n-1 and c==m-1)break;
        pq.pop();
        int currDis = dis[r][c];
        for (int i = 0; i < 4; i++)
        {
            int newX = r + dx[i];
            int newY = c + dy[i];
            if(newX>=0 and newX<n and newY>=0 and newY<m){
             int diff=abs(heights[r][c]-heights[newX][newY]);
             int effort = max(diff, wt);
             if(dis[newX][newY]>effort){
                 dis[newX][newY] = effort;
             pq.push({effort, {newX, newY}});
             }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;  j< m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    cout << dis[n - 1][m - 1] << endl;

    return 0;
}