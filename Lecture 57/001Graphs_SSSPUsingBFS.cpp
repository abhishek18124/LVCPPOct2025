/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

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
#include<algorithm>

using namespace std;

void printPath(int u, vector<int> parMap) {

	vector<int> path = {u};
	while (parMap[u] != -1) {
		u = parMap[u];
		path.push_back(u);
	}

	reverse(path.begin(), path.end());

	for (auto& x : path) {
		cout << x << " ";
	}

	cout << endl;

}

int main() {

	// time  : O(V+2E)
	// space : O(V)

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int s = 0; // source node

	vector<int> distMap(n);
	distMap[s] = 0;

	queue<int> q;
	q.push(s);

	vector<bool> vis(n, false);
	vis[s] = true;

	vector<int> parMap(n);
	parMap[s] = -1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int ngb : adj[cur]) {
			if (!vis[ngb]) {
				vis[ngb] = true;
				q.push(ngb);
				// since we are visiting ngb due to cur
				// it means cur is the parent of ngb in
				// the bfs tree therefore
				distMap[ngb] = distMap[cur] + 1;
				parMap[ngb] = cur;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << "distMap[" << i << "] = " << distMap[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "parMap[" << i << "] =  " << parMap[i] << endl;
	}

	cout << endl;

	int dst = 8;

	printPath(dst, parMap);

	return 0;
}