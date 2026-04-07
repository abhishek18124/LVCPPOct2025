// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
	vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

		vector<vector<int>> adj(n);
		for (vector<int> preq : prerequisites) {
			int ai = preq[0];
			int bi = preq[1];
			adj[bi].push_back(ai);
		}


		vector<int> ans; // to track the topological ordering

		vector<int> indegMap(n, 0);

		for (int i = 0; i < n; i++) {
			for (int ngb : adj[i]) {
				indegMap[ngb]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (indegMap[i] == 0) {
				// node i has no dependencies
				q.push(i);
			}
		}

		while (!q.empty()) {

			int cur = q.front();
			q.pop();

			// process the cur node

			ans.push_back(cur);

			for (int ngb : adj[cur]) {
				indegMap[ngb]--;
				if (indegMap[ngb] == 0) {
					q.push(ngb);
				}
			}

		}

		return ans.size() == n ? ans : vector<int>();

	}
};