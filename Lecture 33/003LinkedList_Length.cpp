#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};


void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

// time : O(n)
// space: O(1)

int computeLengthIterative(ListNode* head) {
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

// time : O(n)
// space: O(n) due to fn call stack

int computeLengthRecursive(ListNode* head) {

	// base case

	if (head == NULL) {
		// f(NULL) : find the len of an empty linkedList
		return 0;
	}

	// recursive case

	// f(head) : find the len of the given linkedList

	// 1. ask your friend to find the len of the sublist
	// that starts from the node which comes after the head node

	int x = computeLengthRecursive(head->next);

	// 2. use the answer given by your friend to solve the org. prob.

	return 1 + x;

}

int main() {

	ListNode* head = NULL; // initially, linkedList empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	cout << computeLengthIterative(head) << endl;

	cout << computeLengthRecursive(head) << endl;

	return 0;
}