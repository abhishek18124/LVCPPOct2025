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

	// time : O(n)
	// space: O(h) due to stack<>

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		TreeNode* cur = root;
		stack<pair<TreeNode*, int>> s;
		while (!s.empty() or cur != NULL) {
			if (cur != NULL) {
				s.push({cur, 1});
				cur = cur->left;
			} else {

				auto& [node, status] = s.top();
				if (status == 1) {
					status = 2;
					cur = node->right;
				} else {
					// status == 2
					s.pop();
					ans.push_back(node->val);
				}

				// pair<TreeNode*, int>& p = s.top();
				// if(p.second == 1) {
				//     p.second = 2;
				//     cur = p.first->right;
				// } else {
				//     // p.second == 2
				//     s.pop();
				//     ans.push_back(p.first->val);
				// }
			}
		}
		return ans;
	}
};