/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v, w (0 <= u, v < n) where u, v are edge endpoints and w is edge weight .

input :

5 7
0 1 7
0 2 1
1 3 2
2 3 9
2 4 6
3 4 5

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w}); // adj[u].push_back(make_pair(v, w));
		adj[v].push_back({u, w});
	}


	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") : ";
		for (pair<int, int> p : adj[i]) {
			int ngb = p.first;
			int edgeWt = p.second;
			cout << "(" << ngb << ", " << edgeWt << ") ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") : ";
		for (auto [ngb, edgeWt] : adj[i]) {
			cout << "(" << ngb << ", " << edgeWt << ") ";
		}
		cout << endl;
	}

	cout << endl;


	return 0;

}