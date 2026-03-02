/*

	Given an array of n integers, sort the array using heap sort algorithm.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) { // time : O(logn)

	// fix the maxHeap prop. at the node that has index i

	int maxIdx = i;
	int leftChildIdx = 2 * i + 1;
	if (leftChildIdx < n and v[leftChildIdx] > v[maxIdx]) {
		maxIdx = leftChildIdx;
	}

	int rightChildIdx = 2 * i + 2;
	if (rightChildIdx < n and v[rightChildIdx] > v[maxIdx]) {
		maxIdx = rightChildIdx;
	}

	if (maxIdx != i) {
		// heap prop. is definitely getting violated at the
		// node with index i
		swap(v[i], v[maxIdx]);
		heapify(v, n, maxIdx);
	}

}

int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// 1. transform v[] into a maxHeap // time : O(n)

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	// 2. transform maxHeap into a sorted vector : O(nlogn)

	int heapsize = n;

	while (heapsize > 1) {
		swap(v[0], v[heapsize - 1]); // const
		heapsize--; // const
		heapify(v, heapsize, 0); // logn
	}

	// time : n + nlogn ~ O(nlogn)
	// space: O(logn) due to fn call stack of heapify
	// [HW] space can be optimised to O(1) if we implement heapify iteratively

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}