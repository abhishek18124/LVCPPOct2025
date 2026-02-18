#include<iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

	bool dfs(TreeNode* root, int t) {

		// base case
		if (root == NULL) {
			return false;
		}

		if (root->left == NULL and root->right == NULL) { // you've reached a leaf node
			if (root->val == t) {
				// you've found a valid path
				return true;
			}
			// current path is not valid
			return false;
		}

		// recursive case

		// f(root, t) : check if there exists a root-to-leaf path
		// whose sum is equal to t

		return dfs(root->left, t - root->val) or dfs(root->right, t - root->val);

	}

	bool hasPathSum(TreeNode* root, int t) {
		return dfs(root, t);
	}
};