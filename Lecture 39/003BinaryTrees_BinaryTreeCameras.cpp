// https://leetcode.com/problems/binary-tree-cameras/

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

class MyTriple {
public:
	int numCam;
	bool isCov;
	bool hasCam;
};

class Solution {
public:

	MyTriple dfs(TreeNode* root) {

		MyTriple t;

		// base case
		if (root == NULL) {
			t.numCam = 0;
			t.isCov = true;
			t.hasCam = false;
			return t;
		}

		// recursive case

		MyTriple left = dfs(root->left);
		MyTriple right = dfs(root->right);

		// decide if cam needs to be installed at the root node
		if (!left.isCov or !right.isCov) {
			// we've install cam at root
			t.numCam = left.numCam + right.numCam + 1;
			t.isCov = true;
			t.hasCam = true;

		} else {
			// we'll not install cam at root
			t.numCam = left.numCam + right.numCam;
			t.isCov = left.hasCam or right.hasCam ? true : false;
			t.hasCam = false;
		}

		return t;

	}

	int minCameraCover(TreeNode* root) {
		MyTriple t = dfs(root);
		if (t.isCov == false) {
			// root node is not covered so install a camera at the root
			return 1 + t.numCam;
		} else {
			return t.numCam;
		}
	}
};