/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, const vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& stackState) {

	stackState[cur] = true;
	vis[cur] = true;

	for (int ngb : adj[cur]) {

		if (!vis[ngb]) {

			// ngb is not vis, recursively visit the ngb

			if (dfs(ngb, adj, vis, stackState)) {

				// we've found a cycle in the subcomponent of ngb
				// hence we've found a cycle in the component of cur

				return true;

			}

		} else {

			// ngb is already visited

			// check if cur -> ngb is a backedge

			// check if there is a directed path from ngb to cur

			// check if ngb is on the function call stack while we are at cur

			if (stackState[ngb] == true) {

				// ngb is on the fn call stack while we are at cur

				// therefore there is a directed path from ngb to cur

				// hence we can say the edge from cur to nbg is a back edge

				// so we've found a directed cycle in the component of cur

				return true;


			}

		}

	}

	stackState[cur] = false; // very component

	return false; // no cycle found in the component of cur

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<bool> vis(n, false);
	vector<bool> stackState(n, false);

	bool flag = false; // assume no directed cycle is present

	for (int i = 0; i < n; i++) {

		if (!vis[i]) {

			// check if there is directed cycle present

			// in the component of node i

			if (dfs(i, adj, vis, stackState)) {

				// we've found a cycle in the component of node i

				// which means we've found a cycle in the given

				// graph

				flag = true;

				break;

			}

		}

	}

	if (flag) {

		cout << "directed cycle found" << endl;

	} else {

		cout << "not directed cycle found" << endl;

	}

	return 0;

}