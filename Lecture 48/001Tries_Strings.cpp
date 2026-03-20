/*

Implementation of the TRIE data structure to store strings.

Motivation :

Given an array of N strings, and an array of Q queries,
check for each query if it is present in the array or not.

*/

#include<iostream>
#include<map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	map<char, node*> childMap;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
	}

};

class trie {
	node* root;

public :

	trie() {
		root = new node('#');
	}

	// time : O(len of str)

	void insert(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
		}
		cur->terminal = true;
	}

	// time : O(len of str)

	bool search(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				return false; // str is not present in the trie
			}
			cur = cur->childMap[ch];
		}
		return cur->terminal;
	}
};

int main() {

	string words[] = {"code", "coder", "coding", "block", "blocks", "news"};

	trie t;
	for (string w : words) {
		t.insert(w);
	}

	string queries[] = {"code", "coding", "blocked", "block", "news", "new"};

	for (string q : queries) {
		t.search(q) ? cout << q << " is present" << endl :
		                   cout << q << " is absent" << endl;
	}

	cout << endl;

	return 0;
}