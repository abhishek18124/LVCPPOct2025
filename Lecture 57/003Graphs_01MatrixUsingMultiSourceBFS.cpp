class Solution {
public:

    // time : O(mn) since we are using multi-source bfs

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> distMat(m, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    // (i, j)th cell corresponds to a source node
                    q.push({i, j});
                    distMat[i][j] = 0;
                }
            }
        }

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};

        while (!q.empty()) {

            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 and nx < m and ny >= 0 and ny < n and distMat[nx][ny] == INT_MAX) {
                    q.push({nx, ny});
                    distMat[nx][ny] = distMat[i][j] + 1;
                }
            }

        }

        return distMat;

    }
};