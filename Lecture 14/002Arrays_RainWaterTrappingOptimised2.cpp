class Solution {
public:

    // time : 2n.const ~ O(n)
    // space: n ~ O(n) due to r[]

    int trap(vector<int>& height) {

        int n = height.size();

        // 2. precompute r[]

        vector<int> r(n);
        r[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r[i] = max(r[i + 1], height[i]); // r[i] = max(height[i...n-1])
        }

        // 3. find total water trapped b/w buildings

        int total = 0;
        int maxSoFar = 0; // to track the max(height[0...i]) // it plays the role of li

        for (int i = 0; i < n; i++) {

            maxSoFar = max(maxSoFar, height[i]);

            // find out the water trapped on top of the ith building

            // li = max(height[0...i])

            // ri = max(heigh[i...n-1])

            int wi = min(maxSoFar, r[i]) - height[i];
            total += wi;

        }

        return total;

    }
};