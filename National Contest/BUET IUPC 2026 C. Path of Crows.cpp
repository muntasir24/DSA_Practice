#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
struct abc {
  int a, b, c;
};

bool dfs(int node, int parent, int target, vector<int>& path,
         vector<vector<int>>& adj) {
  if (node == target) {
    path.push_back(node);
    return true;
  }

  for (auto child : adj[node]) {
    if (child != parent) {
      if (dfs(child, node, target, path, adj)) {
        path.push_back(node);
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test_case;
  cin >> test_case;
  while (test_case--) {
    int n, m;
    cin >> n;
    vector<int> v(n), path;

    vector<abc> ans;

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, val;
      cin >> u >> val;
      adj[u].push_back(val);
      adj[val].push_back(u);
    }

    for (int i = 0; i < n - 1; ++i) {
      dfs(v[i], v[i], v[i + 1], path, adj);
      int a, b, c = v[i];
      for (int i = 0; i < path.size() - 2; ++i) {
        if (i == 0) {
          a = path[0];
          b = path[1];
          // cout << a << " " << b << " " << c << endl;
          // cout << " path start " << endl;

          auto it1 = find(adj[a].begin(), adj[a].end(), b);
          if (it1 != adj[a].end()) {
            adj[a].erase(it1);
          }

          auto it2 = find(adj[b].begin(), adj[b].end(), a);
          if (it2 != adj[b].end()) {
            adj[b].erase(it2);
          }
          adj[a].push_back(c);
          adj[c].push_back(a);
        }
        ans.push_back({path[0], path[i + 1], path[i + 2]});
        // cout << path[0] << " " << path[i + 1] << " " << path[i + 2] << endl;
      }
      path.clear();
      // cout << endl;
      // cout << "end  " << i << endl;
    }
    // for (int i = 1; i <= n; ++i) {
    //   cout << i << " node " << endl;
    //   for (auto u : adj[i]) cout << u << " ";
    //   cout << endl;
    // }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
    }
  }

  return 0;
}