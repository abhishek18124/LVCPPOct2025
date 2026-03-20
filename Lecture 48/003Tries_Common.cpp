#include<iostream>
#include<map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0;
	}

};

class trie {
	node* root;
	int n; // to track no. of words in the trie

public :

	trie() {
		root = new node('#');
		n = 0;
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
			cur->freq++;
		}
		cur->terminal = true;
		n++;
	}

	string longestCommonPrefix(string str) {
		string ans = "";
		node* cur = root;
		for (char ch : str) {
			cur = cur->childMap[ch];
			if (cur->freq != n) {
				break;
			}
			ans += ch;
		}
		return ans;
	}

};

int main() {

	string words[] = {"fly", "flys"};

	trie t;
	for (string w : words) {
		t.insert(w);
	}

	cout << t.longestCommonPrefix(words[0]) << endl;

	return 0;
}