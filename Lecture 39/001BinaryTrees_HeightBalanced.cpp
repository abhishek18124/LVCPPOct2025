
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

*/

#include<iostream>
#include<cmath>

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


TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int findHeight(TreeNode* root) {

	// base case

	if (root == NULL) {
		// height of empty tree is -1
		return -1;
	}

	// recursive case

	// 1. recursively find the height of the leftSubtree
	int leftHgt = findHeight(root->left);

	// 2. recursively find the height of the rightSubtree
	int rightHgt = findHeight(root->right);

	return 1 + max(leftHgt, rightHgt);

}

// time : O(n^2) if tree is skewed // space : O(n) if tree is skewed due to fn call stack
// time : O(nlogn) if tree is perfect // space : O(logn) if tree is perfect due to fn call stack
// space: O(h) where h is the height of the tree

bool checkHeightBalanced(TreeNode* root) {

	// base case

	if (root == NULL) {
		// when root is NULL it means tree is empty
		// and since there are no violations of HB
		// prop. in an empty we assume an empty tree
		// to be HB
		return true;
	}

	// recursive case

	// f(root) : check if the given tree is height balanced or not

	// 1. ask your friend to check if the leftSubtree is height balanced

	bool leftIsBal = checkHeightBalanced(root->left);

	// 2. ask your friend to check if the rightSubtree is height balanced

	bool rightIsBal = checkHeightBalanced(root->right);

	// 3. check if the height balance prop. works at the root node

	bool doesHBPropWorkAtRoot = abs(findHeight(root->left) - findHeight(root->right)) <= 1 ? true : false;

	return leftIsBal and rightIsBal and doesHBPropWorkAtRoot;

}

// time : O(n)

pair<bool, int> checkHeightBalancedOptimised(TreeNode* root) {

	pair<bool, int> p;

	// base case

	if (root == NULL) {
		p.first = true;
		p.second = -1;
		return p;
	}

	// recursive case

	// 1. ask your friend to check if the leftSubtree is height balanced or not and also ask your friend to simulataneously find the height of the leftSubtree

	pair<bool, int> left = checkHeightBalancedOptimised(root->left);

	// 2. ask your friend to check if the rightSubtree is height balanced or not and also ask your friend to simulataneously find the height of the rightSubtree

	pair<bool, int> right = checkHeightBalancedOptimised(root->right);

	// 3. check if the height balance prop. works at the root node

	bool doesHBPropWorkAtRoot = abs(left.second - right.second) <= 1 ? true : false;

	p.first = left.first and right.first and doesHBPropWorkAtRoot;
	p.second = 1 + max(left.second, right.second);

	return p;

}

int main() {

	TreeNode* root = buildTree();

	checkHeightBalanced(root) ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	pair<bool, int> p = checkHeightBalancedOptimised(root);

	// p.first tells if the given tree is height-balanced or not
	// p.second tell the height of the given tree

	p.first ? cout << "height-balanced!" << endl : cout << "not height-balanced" << endl;

	return 0;
}