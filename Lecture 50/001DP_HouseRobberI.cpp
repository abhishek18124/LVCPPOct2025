class Solution {
public:

    // time : O(2^n)
    // space: O(n) due to fn call stack

    int f(const vector<int>& nums, int n, int i) {

        // base case

        if (i == n or i == n + 1) {
            return 0;
        }

        // recursive case

        // f(i) : find the max. money you can rob from house[i...n-1]

        // decide for the ith house

        // option 1 : rob the ith house

        int robOption = nums[i] + f(nums, n, i + 2);

        // option 2 : don't rob the ith house

        int donotRobOption = f(nums, n, i + 1);

        return max(robOption, donotRobOption);

    }

    // time : O(n)
    // space: O(n) due to dp[] + fn call stack

    int fTopdown(const vector<int>& nums, int n, int i, vector<int>& dp) {

        // lookup

        if (dp[i] != -1) {
            return dp[i];
        }

        // base case

        if (i == n or i == n + 1) {
            return dp[i] = 0;
        }

        // recursive case

        // f(i) : find the max. money you can rob from house[i...n-1]

        // decide for the ith house

        // option 1 : rob the ith house

        int robOption = nums[i] + fTopdown(nums, n, i + 2, dp);

        // option 2 : don't rob the ith house

        int donotRobOption = fTopdown(nums, n, i + 1, dp);

        return dp[i] = max(robOption, donotRobOption);

    }

    // time : O(n)
    // space: O(n) due to dp[], can be optimised to O(1)

    int fBottomUp(const vector<int>& nums, int n) {

        vector<int> dp(n + 2);

        dp[n + 1] = 0; // at the n+1th index of dp[] we store f(n+1)
        dp[n] = 0; // at the nth index of dp[] we store f(n)

        for (int i = n - 1; i >= 0; i--) {

            // dp[i] = f(i) = find the max. money you can rob
            // from houses[i...n-1] w/o alerting the police

            // decide for the ith house

            // option 1 : rob the ith house

            int robOption = nums[i] + dp[i + 2];

            // option 2 : don't rob the ith house

            int donotRobOption = dp[i + 1];

            dp[i] = max(robOption, donotRobOption);

        }

        return dp[0]; // at the 0th index of dp[] we store f(0)

    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        // return f(nums, n, 0);

        // vector<int> dp(n + 2, -1);
        // return fTopdown(nums, n, 0, dp);

        return fBottomUp(nums, n);

    }
};