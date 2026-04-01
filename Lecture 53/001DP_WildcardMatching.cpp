/*

    https://leetcode.com/problems/wildcard-matching/

*/

class Solution {
public:

    bool f(const string& s, const string& p, int m, int n, int i, int j) {

        // base case

        if (i == m) {
            bool flag = true; // assume p[j...n-1] matches empty s[]
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            return flag;
        }

        if (j == n) {
            return false;
        }

        // recursive case

        // f(i, j) : check if p[j...n-1] matches s[i...m-1]

        if (p[j] == s[i] or p[j] == '?') {
            return f(s, p, m, n, i + 1, j + 1);
        } else if (p[j] == '*') {
            return f(s, p, m, n, i, j + 1) or
                   f(s, p, m, n, i + 1, j);
        } else {
            return false;
        }

    }

    // time : O(mn)
    // space: O(mn) due to dp[][]

    bool fTopdown(const string& s, const string& p, int m, int n, int i, int j, vector<vector<int>>& dp) {

        // lookup
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // base case

        if (i == m) {
            bool flag = true; // assume p[j...n-1] matches empty s[]
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            return dp[i][j] = flag;
        }

        if (j == n) {
            return dp[i][j] = false;
        }

        // recursive case

        // f(i, j) : check if p[j...n-1] matches s[i...m-1]

        if (p[j] == s[i] or p[j] == '?') {
            return dp[i][j] = fTopdown(s, p, m, n, i + 1, j + 1, dp);
        } else if (p[j] == '*') {
            return dp[i][j] = fTopdown(s, p, m, n, i, j + 1, dp) or
                              fTopdown(s, p, m, n, i + 1, j, dp);
        } else {
            return dp[i][j] = false;
        }

    }

    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        // return f(s, p, m, n, 0, 0);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return fTopdown(s, p, m, n, 0, 0, dp);

    }
};