/*

given the in-order & pre-order traversal of a binary tree, design an algorithm to construct
a binary tree from it.

Example
	Input: pre[] = {10, 20, 40, 50, 70, 30, 60}
	       in[]  = {40, 20, 70, 50, 10, 30, 60}

*/

#include<iostream>
#include<vector>
#include<queue>

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

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if (front->left) q.push(front->left);
			if (front->right)q.push(front->right);
		}
	}

}

void printPreOrder(TreeNode* root) {
	if (root == NULL) {
		// root represents an empty tree
		return;
	}

	cout << root->val << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}


void printInOrder(TreeNode* root) {
	if (root == NULL) {
		// root represents an empty tree
		return;
	}

	printInOrder(root->left);
	cout << root->val << " ";
	printInOrder(root->right);
}

int i = 0; // to iterate over preOrder

TreeNode* buildTree(const vector<int>& preOrder,
                    const vector<int>& inOrder,
                    int s, int e) {

	// base case
	if (s > e) {
		return NULL;
	}

	// recursive case

	int key = preOrder[i]; i++;
	TreeNode* root = new TreeNode(key);

	// search for the key in inOrder[s...e]

	int keyIndex;
	for (keyIndex = s; keyIndex <= e; keyIndex++) {
		if (inOrder[keyIndex] == key) {
			break;
		}
	}

	// ask your friend to build the leftSubtree
	// from its inOrder[s...keyIndex-1]

	root->left = buildTree(preOrder, inOrder, s, keyIndex - 1);

	// ask your friend to build the rightSubtree
	// from its inOrder[keyIndex+1...e]

	root->right = buildTree(preOrder, inOrder, keyIndex + 1, e);

	return root;


}

int main() {

	vector<int> preOrder = {10, 20, 40, 50, 70, 30, 60};
	vector<int> inOrder  = {40, 20, 70, 50, 10, 30, 60};
	int n = preOrder.size(); // no. of nodes in the tree

	TreeNode* root = buildTree(preOrder, inOrder, 0, n - 1);

	printPreOrder(root);
	cout << endl;

	printInOrder(root);
	cout << endl;

	printLevelOrder(root);
	cout << endl;

	return 0;
}