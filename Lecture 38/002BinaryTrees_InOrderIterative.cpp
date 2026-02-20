// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> ans;
		TreeNode* cur = root;
		while (!s.empty() or cur != NULL) {
			if (cur != NULL) {
				s.push(cur);
				cur = cur->left;
			} else {
				cur = s.top(); s.pop();
				ans.push_back(cur->val);
				cur = cur->right;
			}
		}
		return ans;
	}
};