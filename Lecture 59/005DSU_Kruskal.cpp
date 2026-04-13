/*

kruskals algorithm using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 9

1 2 4
1 3 5
2 4 2
2 5 7
3 4 6
3 6 9
5 6 1
5 7 3
6 7 8

output :

22

*/

#include<iostream>
#include<vector>
#include<algorithm>

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

	vector<vector<int>> edges; // each edge is represented by a 3-sized vector
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}

	// n or |V| : no. of nodes
	// m or |E| : no. of edges

	// when you sort a vector<vector<int>> using sort(...) then sorting is done on the 1st member of the internal vector that is why we store weight of the edge first in the internal vector

	sort(edges.begin(), edges.end()); // ElogE

	disjointSet ds(n); // V.const

	for (int i = 1; i <= n; i++) {
		ds.createSet(i);
	}

	vector<vector<int>> ans; // to track |V|-1 safe edges present in the MST
	int mstSum = 0;

	for (vector<int> e : edges) { // |E|.const
		int w = e[0];
		int u = e[1];
		int v = e[2];
		if (ds.findSet(u) != ds.findSet(v)) {
			// uv is a safe edge
			ans.push_back(e);
			mstSum += w;
			ds.unionSet(u, v);
			if (ans.size() == n - 1) {
				// we've picked n-1 safe edges so we can stop
				break;
			}
		}
	}

	// time : ElogE + V + E ~ O(ElogE)
	// space: O(V) due to disjointSet

	cout << mstSum << endl;

	for (vector<int> e : ans) {
		int w = e[0];
		int u = e[1];
		int v = e[2];
		cout << "(" << u << ", " << v << ") : " << w << endl;
	}

	return 0;
}