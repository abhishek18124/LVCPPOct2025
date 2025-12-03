class Solution {
public:

    // time : O(n)
    // space: O(1)

    int maxArea(vector<int>& height) {

        int maxSoFar = 0;
        int n = height.size();

        int i = 0;
        int j = n - 1;

        while (i < j) {
            // find the area of the container which can be
            // formed using the ith and jth line
            int width_ij = j - i;
            int height_ij = min(height[i], height[j]);
            int area_ij = width_ij * height_ij;
            maxSoFar = max(maxSoFar, area_ij);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxSoFar;

    }
};