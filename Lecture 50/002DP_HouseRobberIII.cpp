// https://leetcode.com/problems/house-robber-iii/

class Solution {
public:

    int f(TreeNode* root) {

        // base case

        if (root == NULL) {
            return 0;
        }

        // recursive case

        // f(root) : find the max. money that can be robbed
        // from the given tree i.e. subtree rooted at 'root'

        // decide for the root node

        // option 1 : don't rob the root node

        int donotRobOption = f(root->left) + f(root->right);

        // option 2 : rob the root node

        int robOption = root->val;

        if (root->left != NULL) {
            robOption += f(root->left->left);
            robOption += f(root->left->right);
        }

        if (root->right != NULL) {
            robOption += f(root->right->left);
            robOption += f(root->right->right);
        }

        return max(donotRobOption, robOption);

    }

    // time : O(nlogn)
    // space: O(n) due to map<> + fn call stack

    int fTopdown(TreeNode* root, map<TreeNode*, int>& dp) {

        // lookup

        if (dp.find(root) != dp.end()) {
            return dp[root];
        }

        // base case

        if (root == NULL) {
            return dp[root] = 0;
        }

        // recursive case

        // f(root) : find the max. money that can be robbed
        // from the given tree i.e. subtree rooted at 'root'

        // decide for the root node

        // option 1 : don't rob the root node

        int donotRobOption = fTopdown(root->left, dp) + fTopdown(root->right, dp);

        // option 2 : rob the root node

        int robOption = root->val;

        if (root->left != NULL) {
            robOption += fTopdown(root->left->left, dp);
            robOption += fTopdown(root->left->right, dp);
        }

        if (root->right != NULL) {
            robOption += fTopdown(root->right->left, dp);
            robOption += fTopdown(root->right->right, dp);
        }

        return dp[root] = max(donotRobOption, robOption);

    }

    int rob(TreeNode* root) {

        // return f(root);

        map<TreeNode*, int> dp;

        return fTopdown(root, dp);

    }
};