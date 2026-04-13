/*

cycle detection in an undirected graph using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

4 4

1 2
2 3
3 4
4 1

output :

true

*/

#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

	vector<int> parMap;
	vector<int> rankMap;

public:

	disjointSet(int n) {
		parMap.resize(n + 1);
		rankMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
		rankMap[x] = 0;
	}

	int findSet(int x) {
		// base case
		if (parMap[x] == x) {
			return x;
		}

		// recursive case

		return parMap[x] = findSet(parMap[x]); // path compression
	}

	void unionSet(int x, int y) { // union by rank

		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {

			if (rankMap[lx] == rankMap[ly]) {
				rankMap[lx]++;
			}

			if (rankMap[lx] > rankMap[ly]) {
				parMap[ly] = lx;
			} else {
				parMap[lx] = ly;
			}

		}

	}



};


int main() {

	int n, m;
	cin >> n >> m;

	// edgeList Representation

	vector<vector<int>> edges; // each edge can be thought of as a 2-sized vector

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}

	// n or |V| : no. of nodes in the graph
	// m or |E| : no. of edges in the graph

	disjointSet ds(n);

	for (int i = 1; i <= n; i++) {
		ds.createSet(i);
	}

	bool flag = false; // assume no cycle is present

	for (vector<int> e : edges) {
		int u = e[0];
		int v = e[1];
		if (ds.findSet(u) != ds.findSet(v)) {
			ds.unionSet(u, v);
		} else {
			// u and v are in the same set
			// it means u and v are in the same component
			// it means there is a path between u and v
			// and now, we've also found an edge b/w
			// so graph contains a cycle
			flag = true;
			break;
		}
	}

	// time : O(n+m) or O(V+E)
	// space: O(n) or O(V) due to disjointSet (parMap and rankMap)

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "no cycle found" << endl;
	}

	return 0;
}