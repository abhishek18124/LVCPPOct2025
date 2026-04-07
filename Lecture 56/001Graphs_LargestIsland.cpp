// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:

	int dfs(int i, int j, const vector<vector<int>>& grid, vector<vector<bool>>& vis, int m, int n) {

		vis[i][j] = true;

		// find the size of the component in which the node corr. to the (i, j)th cell is present

		int size = 1; // to track the size of the component of the node corr. to the (i, j)th cell

		int nx = i;
		int ny = j + 1;

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			size += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i;
		ny = j - 1;

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			size += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i - 1;
		ny = j;

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			size += dfs(nx, ny, grid, vis, m, n);
		}

		nx = i + 1;
		ny = j;

		if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
			size += dfs(nx, ny, grid, vis, m, n);
		}

		return size;

	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<bool>> vis(m, vector<bool>(n, false));

		int maxSoFar = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 and !vis[i][j]) {

					// find the size of the component of the node

					// correponding to the i,jth cell

					maxSoFar = max(maxSoFar, dfs(i, j, grid, vis, m, n));

				}
			}
		}

		return maxSoFar;

	}
};