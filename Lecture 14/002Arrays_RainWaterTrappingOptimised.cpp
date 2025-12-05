class Solution {
public:

    // time : 3n.const ~ O(n)
    // space: 2n ~ O(n) due to l[] and r[]

    int trap(vector<int>& height) {

        int n = height.size();

        // 1. precompute l[]

        vector<int> l(n);
        l[0] = height[0];
        for (int i = 1; i < n; i++) {
            l[i] = max(l[i - 1], height[i]); // l[i] = max(height[0...i])
        }

        // 2. precompute r[]

        vector<int> r(n);
        r[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r[i] = max(r[i + 1], height[i]); // r[i] = max(height[i...n-1])
        }

        // 3. find total water trapped b/w buildings

        int total = 0;

        for (int i = 0; i < n; i++) {

            // find out the water trapped on top of the ith building

            // li = max(height[0...i])

            // ri = max(heigh[i...n-1])

            int wi = min(l[i], r[i]) - height[i];
            total += wi;

        }

        return total;

    }
};