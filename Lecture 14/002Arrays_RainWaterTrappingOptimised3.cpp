class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int i = 0;
        int j = n - 1;

        int total = 0;

        int l = 0; // to track max(height[0...i])
        int r = 0; // to track max(height[j...n-1])

        while (i <= j) {

            l = max(l, height[i]);
            r = max(r, height[j]);

            if (l < r) {

                int wi = l - height[i];
                total += wi;
                i++;

            } else {

                int wj = r - height[j];
                total += wj;
                j--;

            }

        }

        return total;

    }
};