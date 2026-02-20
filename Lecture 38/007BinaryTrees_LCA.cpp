// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	// time : O(n)
	// space: O(h) due to function call stack

	TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {

		// base case

		if (root == NULL) {
			return root;
		}

		if (root == p or root == q) {
			return root;
		}

		// recursive case

		// f(root, p, q) : find the lca(p, q) in the given tree

		// 1. ask your friend to find the lca(p, q) in the leftSubtree

		TreeNode* left = dfs(root->left, p, q);

		// 2. ask your friend to find the lca(p, q) in the rightSubtree

		TreeNode* right = dfs(root->right, p, q);

		if (left != NULL and right == NULL) {
			return left;
		} else if (left == NULL and right != NULL) {
			return right;
		} else if (left != NULL and right != NULL) {
			return root;
		} else {
			// left == NULL and right == NULL
			return NULL;
		}

	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		return dfs(root, p, q);
	}
};