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

// time : O(1)

void insertAtHead(ListNode*& head, int val) { // here we are passing head ptr by ref since we want changes done to the head ptr inside this fn to be reflected in the head ptr of caller fn i.e. the main fn
	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;
}

void printLinkedList(ListNode* head) { // here we are passing head ptr by value since we don't want changes done to the head ptr inside this fn to be reflected in the head ptr created in the caller fn i.e. main fn.
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	ListNode* head = NULL; // init, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10); // 10 20 30 40 50

	if (head == NULL) {
		cout << "YES" << endl;
	}

	printLinkedList(head); // 10 20 30 40 50

	if (head == NULL) {
		cout << "YES" << endl;
	}

	printLinkedList(head);

	return 0;
}