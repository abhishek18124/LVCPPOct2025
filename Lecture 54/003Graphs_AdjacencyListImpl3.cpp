/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v where u, v are edge endpoints.

input :

5 6
DL CN
DL MU
CN BE
CN HY
MU HY
HY BE

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<string, vector<string>> adj;
	// map<string, set<string>> adj; // use this if you want ngblist for each node to be sorted

	for (int i = 0; i < m; i++) {
		string u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if graph is directed
	}

	for (pair<string, vector<string>> p : adj) {
		string node = p.first;
		vector<string> ngblist = p.second;
		cout << "ngb(" << node << ") : ";
		for (string ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [node, ngblist] : adj) {
		cout << "ngb(" << node << ") : ";
		for (string ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}