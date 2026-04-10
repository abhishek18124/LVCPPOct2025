/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // since i/p graph is undirected
	}

	int s = 0; // assume node 0 to be the src vertex

	vector<int> distMap(n, INF);
	distMap[s] = 0;

	vector<bool> expl(n, false);

	priority_queue<pair<int, int>,
	               vector<pair<int, int>>,
	               greater<pair<int, int>>> minHeap;
	minHeap.push({distMap[s], s});

	// time : nlogn + mlogn ~ VlogV + ElogV ~ O((E+V)logV)
	// space: O(V) due to minHeap, distMap, expl

	while (!minHeap.empty()) {

		// pair<int, int> p = minHeap.top();
		// minHeap.pop();
		// int du = p.first;
		// int u = p.second;

		auto [du, u] = minHeap.top();
		minHeap.pop();

		if (du > distMap[u]) {
			// pair<> {du, u} is outdated
			continue;
		}

		for (auto [v, w] : adj[u]) {
			if (!expl[v] and distMap[v] > du + w) {
				// edge b/w u and v is tensed so relax that edge
				distMap[v] = du + w;
				minHeap.push({distMap[v], v});
			}
		}

		expl[u] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "distMap[" << i << "] = " << distMap[i] << endl;
	}

	cout << endl;

	return 0;
}