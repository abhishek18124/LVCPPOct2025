/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}

int findMaximum(TreeNode* root) {

	if (root == NULL) {
		// tree is empty
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}

bool checkBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		return true; // empty tree is a BST since there are not BST prop. violations
	}

	// recursive case

	// f(root) : check if the given tree is a BST or not ?

	// 1. ask your friend to check if the leftSubtree is a BST or not

	bool leftIsBst = checkBST(root->left);

	// 2. ask your friend to check if the rightSubtree is a BST or not

	bool rightIsBst = checkBST(root->right);

	// 3. check if the BST prop. works at the root node

	bool isBSTPropWorkingAtRoot = root->val > findMaximum(root->left) and
	                              root->val < findMinimum(root->right) ? true : false;

	return leftIsBst and rightIsBst and isBSTPropWorkingAtRoot;

}

class triple {
public:
	bool isBST;
	int maxVal;
	int minVal;
};

// time : O(n)

triple checkBSTOptimised(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		t.isBST = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;
		return t;
	}

	// recursive case

	triple left = checkBSTOptimised(root->left);
	triple right = checkBSTOptimised(root->right);

	bool isBSTPropWorkingAtRoot = root->val > left.maxVal and
	                              root->val < right.minVal ? true : false;

	t.isBST = left.isBST and right.isBST and isBSTPropWorkingAtRoot;
	t.minVal = min(left.minVal, min(right.minVal, root->val));
	t.maxVal = max(left.maxVal, max(right.maxVal, root->val));

	return t;

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	checkBST(root) ? cout << "given tree is a BST" << endl :
	                      cout << "given tree is not a BST" << endl;

	triple t = checkBSTOptimised(root);

	t.isBST ? cout << "given tree is a BST" << endl :
	               cout << "given tree is not a BST" << endl;

	return 0;
}