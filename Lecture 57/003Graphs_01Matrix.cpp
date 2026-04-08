class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

		int m = mat.size();
		int n = mat[0].size();

		vector<vector<int>> distMat(m, vector<int>(n, INT_MAX));

		// time : (mn).(mn) ~ O(m^2n^2)

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 0) {
					// find the manhattan dist of all the cells
					// in the mat[][] from the (i, j)th cell &
					// track the minimum
					for (int ii = 0; ii < m; ii++) {
						for (int jj = 0; jj < n; jj++) {
							// find the manhattan distance between
							// (i, j)th cell and (ii, jj)th cell
							distMat[ii][jj] = min(distMat[ii][jj],
							                      abs(i - ii) + abs(j - jj));
						}
					}

				}
			}
		}

		return distMat;
	}
};