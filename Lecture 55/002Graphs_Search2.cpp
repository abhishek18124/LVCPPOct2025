/*

Implementation of graph search using

  breadth first search (bfs)

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
#include<queue>

using namespace std;

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

  queue<int> q;
  q.push(s);

  vis[s] = true;

  // time : O(V + 2E) or O(n + 2m)
  // space: n due vis[] + n due to queue ~ O(n) or O(V)

  while (!q.empty()) {

    int cur = q.front();
    q.pop();

    // process the cur node

    cout << cur << " ";

    for (int ngb : adj[cur]) {
      if (!vis[ngb]) {
        q.push(ngb);
        vis[ngb] = true;
      }
    }

  }

  return 0;

}