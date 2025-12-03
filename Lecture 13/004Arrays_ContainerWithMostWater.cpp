class Solution {
public:

	// time : O(n^2)

	int maxArea(vector<int>& height) {

		int n = height.size();

		int maxSoFar = 0;

		for (int i = 0; i <= n - 2; i++) {
			for (int j = i + 1; j <= n - 1; j++) {
				// find the area of the container which can be
				// formed using the ith and jth line
				int width_ij = j - i;
				int height_ij = min(height[i], height[j]);
				int area_ij = width_ij * height_ij;
				maxSoFar = max(maxSoFar, area_ij);
			}
		}

		return maxSoFar;

	}
};