#include <bits/stdc++.h>
using namespace std;

const int dz[] = {1, -1, 0, 0, 0, 0};
const int dx[] = {0, 0, 1, -1, 0, 0};
const int dy[] = {0, 0, 0, 0, 1, -1};

int calc_id(int rows, int cols, int z, int i, int j) {
  return ((z * rows + i) * cols + j);
}

int row_col(int cols, int i, int j) { return (cols * i + j); }

class Disjoint {
 public:
  vector<int> size, parent;
  Disjoint(int n) {
    size.resize(n, 1);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int findUlp(int node) {
    if (node == parent[node]) return node;

    return parent[node] = findUlp(parent[node]);
  }

  void unionBySize(int u, int v) {
    int ulp_u = findUlp(u);
    int ulp_v = findUlp(v);
    if (ulp_u == ulp_v) return;
    if (size[ulp_u] > size[ulp_v]) {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    } else {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
  }
};



int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    vector<vector<string>> mat(z, vector<string>(x));
    for (int i = 0; i < z; i++) {
      for (int j = 0; j < x; j++) {
        cin >> mat[i][j];
      }
    }
    int n = x * y * z;
    vector<int> vis(n, -1);
    Disjoint ds(n);

    for (int k = 0; k < z; k++) {
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
          int node = calc_id(x, y, k, i, j);
          if (mat[k][i][j] == '.') {
            for (int d = 0; d < 6; d++) {
              int nk = k + dz[d];
              int ni = i + dx[d];
              int nj = j + dy[d];
              if (nk >= 0 && nk < z && ni >= 0 && ni < x && nj >= 0 && nj < y) {
                if (mat[nk][ni][nj] == '.') {
                  int adjNode = calc_id(x, y, nk, ni, nj);
                  ds.unionBySize(node, adjNode);
                }
              }
            }
          }
        }
      }
    }

    int mx = 0;
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
        int id = row_col(x, i, j);
        int ans = 0;
        for (int k = 0; k < z; ++k) {
          if (mat[k][i][j] == '.') {
            int ulp = ds.findUlp(calc_id(x, y, k, i, j));
            if (vis[ulp] != id) {
              vis[ulp] = id;
              ans += ds.size[ulp];
            }
          }
        }
        mx = max(mx, ans);
        // cout << i << " " << j << " : " << ans << endl;
      }
    }
    cout << mx << endl;
    // for (int i = 0; i < ds.parent.size(); i++) {
    //   ds.findUlp(i);
    //   cout << i << " " << ds.size[i] << endl;
    // }
  }

  return 0;
}