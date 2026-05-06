#include<bits/stdc++.h>
using namespace std;

class Disjoint{
vector<int> size, parent;
     
      public:
      Disjoint(int n){
          size.resize(n + 1, 1);
          parent.resize(n + 1);
          for (int i = 1; i <=n; i++)
          {
              parent[i] = i;
          }
      }
      int findUparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUparent(parent[node]);
      }
      void unionBySize(int u,int v){
          int ulp_u = findUparent(u);
          int ulp_v = findUparent(v);
          if(ulp_u==ulp_v)
              return;
         else if(size[ulp_v]>size[ulp_u]){
             size[ulp_v] += size[ulp_u];
             parent[ulp_u] = ulp_v;
         }
         else{
              size[ulp_u] += size[ulp_v];
             parent[ulp_v] = ulp_u;
         }
      }
};

int main(){
    int V = 3;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Disjoint ds(V);
    int n = isConnected.size();
    int m = isConnected[0].size();
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            if(isConnected[i][j]==1){
                ds.unionBySize(i+1, j+1);
            }
        }
        
    }
    set<int> st;
    for (int i = 1; i <=n; i++)
    {
        st.insert(ds.findUparent(i));
    }
    cout << st.size() << endl;

    return 0;
}