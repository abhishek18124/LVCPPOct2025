/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class minHeap {

	vector<int> v; // internal representation of the minHeap

	void heapify(int i) { // time : O(logn)

		// fix the minHeap prop. at the node that has index i

		int minIdx = i;
		int leftChildIdx = 2 * i + 1;
		if (leftChildIdx < v.size() and v[leftChildIdx] < v[minIdx]) {
			minIdx = leftChildIdx;
		}

		int rightChildIdx = 2 * i + 2;
		if (rightChildIdx < v.size() and v[rightChildIdx] < v[minIdx]) {
			minIdx = rightChildIdx;
		}

		if (minIdx != i) {
			// heap prop. is definitely getting violated at the
			// node with index i
			swap(v[i], v[minIdx]);
			heapify(minIdx);
		}

	}

public:

	// time : O(logn)

	void push(int val) {
		v.push_back(val);
		int childIdx = v.size() - 1;
		int parentIdx = (childIdx - 1) / 2;
		while (childIdx != 0 and v[childIdx] < v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = (childIdx - 1) / 2;
		}
	}

	// time : O(logn)

	void pop() {
		swap(v[0], v[v.size() - 1]); // const
		v.pop_back(); // const
		heapify(0); // logn
	}

	// time : O(1)

	int top() {
		return v[0];
	}

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

};

int main() {

	minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl; // 9

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}



