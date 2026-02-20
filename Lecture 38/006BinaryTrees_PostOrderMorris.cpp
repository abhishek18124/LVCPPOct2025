// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		TreeNode* cur = root;
		while (cur != NULL) {
			if (cur->right == NULL) {
				ans.push_back(cur->val);
				cur = cur->left;
			} else {
				TreeNode* temp = cur->right;
				while (temp->left != NULL and temp->left != cur) {
					temp = temp->left;
				}
				if (temp->left == NULL) { // adding link
					temp->left = cur;
					ans.push_back(cur->val);
					cur = cur->right;
				} else { // removing link
					temp->left = NULL;
					cur = cur->left;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};