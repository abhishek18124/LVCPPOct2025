/*

Given an undirected graph, check if it is bipartite or not.

	e.g.

	5 5

	0 1
	0 2
	1 3
	2 4
	3 4

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool bfs(int s, const vector<vector<int>>& adj, vector<int>& colorMap) {


	queue<int> q;
	q.push(s);

	// 0 : blue color
	// 1 : red color

	colorMap[s] = 0;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int ngb : adj[cur]) {

			if (colorMap[ngb] == -1) {

				// ngb is not yet colored / visited

				q.push(ngb);
				colorMap[ngb] = 1 - colorMap[cur];

			} else {

				// ngb is already colored / visted

				if (colorMap[cur] == colorMap[ngb]) {

					// component of s is not bipartite

					return false;

				}

			}

		}

	}

	// component of s is bipartite

	return true;

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

	vector<int> colorMap(n, -1);

	bool flag = true; // assume graph is bipartite

	for (int i = 0; i < n; i++) {

		if (colorMap[i] == -1) {

			// check if the component of node i is biparite or not using dfs or bfs

			if (bfs(i, adj, colorMap) == false) {

				// component of node i is not bipartite

				// therefore given graph is also not

				// bipartite

				flag = false;

				break;

			}

		}

	}

	if (flag) {

		cout << "bipartite" << endl;

	} else {

		cout << "not bipartite" << endl;

	}


	return 0;

}