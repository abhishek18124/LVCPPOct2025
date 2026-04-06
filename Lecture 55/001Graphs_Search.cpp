/*

Implementation of graph search using

  depth first search   (dfs)

  e.g.

  9 12

  0  1
  0  2
  1  3
  1  4
  2  4
  2  5
  3  6
  4  6
  4  7
  5  7
  6  8
  7  8

*/

#include<iostream>
#include<vector>

using namespace std;

// time : O(V + 2E) or O(n + 2m)
// space: n due to vis[] + n due func. call stack ~ O(n) or O(V)

void dfs(int cur, const vector<vector<int>>& adj, vector<bool>& vis) {

  vis[cur] = true;
  cout << cur << " ";

  for (int ngb : adj[cur]) {
    if (!vis[ngb]) {
      dfs(ngb, adj, vis);
    }
  }

}

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // comment this out if graph is directed
  }

  int s = 0; // source vertex / node

  vector<bool> vis(n, false);

  dfs(s, adj, vis);

  return 0;

}