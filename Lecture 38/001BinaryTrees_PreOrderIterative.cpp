// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

	// time : O(n)
	// space: O(h) due to stack<>

	vector<int> preorderTraversal(TreeNode* root) {
		TreeNode* cur = root;
		stack<TreeNode*> s;
		vector<int> ans;
		while (!s.empty() or cur != NULL) {
			if (cur != NULL) {
				ans.push_back(cur->val);
				s.push(cur->right);
				cur = cur->left;
			} else {
				cur = s.top();
				s.pop();
			}
		}
		return ans;
	}
};