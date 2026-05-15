#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    vector<int> parent;
    vector<int> size;
    public:
    Disjoint(int n){
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUlParent(int node){
        if(node==parent[node])
            return node;
        return parent[node] = findUlParent(parent[node]);
    }
    int unionBySize(int u,int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if(ulp_u==ulp_v)
            return 0;
        else if(size[ulp_u]>size[ulp_v]){
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        else{
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v; 
        }
        return 1;
    }
};

int main(){
    int n = 4, m = 5, k = 12;
    vector<vector<int>> A = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};
    vector<vector<int>> mat(n, vector<int>(m,0));
    map<pair<int, int>, int> mp;
    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        auto el = A[i];
        if(mp.find({el[0],el[1]})==mp.end()){
            mp[{el[0], el[1]}] = cnt;
            cnt++;
        }
    }
    Disjoint ds(cnt);
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<int> ans;
    int tmpcnt, curcnt=0;
    for (int i = 0; i < A.size(); i++)
    {
        auto el = A[i];
        int x = el[0];
        int y = el[1];
        //cout << x << " " << y << " " << mat[x][y] << endl;
        if (mat[x][y]==1){
            //cout << curcnt << " " << tmpcnt << endl;
        // curcnt -= (tmpcnt - 1);
        //cout << curcnt << endl;
            ans.push_back(curcnt);
            continue;
        }
            
        mat[x][y] = 1;
        int u = mp[{x, y}];
        tmpcnt = 0;
        for (int j = 0; j < 4; j++)
        {
            int newX = dx[j] + x;
            int newY = dy[j] + y;
            
            if (newX >= 0 and newX < n and newY >=0  and newY < m)
            {
                if(mat[newX][newY]==1){
                    tmpcnt += ds.unionBySize(u, mp[{newX, newY}]);
                }
            }
        }
        //cout << curcnt << " " << tmpcnt << endl;
        curcnt -= (tmpcnt - 1);
        //cout << curcnt << endl;
        ans.push_back(curcnt);
    }
    for (int i = 0; i <ans.size(); i++)
    {
        // cout << ans[i]<<" ";
    }

    return 0;
}