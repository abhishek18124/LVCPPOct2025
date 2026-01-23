#include<iostream>
#include<set>

using namespace std;

int main() {

	multiset<int> ms;

	ms.insert(1);
	ms.insert(1);
	ms.insert(1);
	ms.insert(2);
	ms.insert(5);
	ms.insert(4);
	ms.insert(3);

	cout << "size = " << ms.size() << endl;

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.erase(1); // it erases all occurrences of 1 in the multiset<>

	cout << "size = " << ms.size() << endl;

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.insert(2);

	cout << "size = " << ms.size() << endl;

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.erase(ms.begin());

	cout << "size = " << ms.size() << endl;

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.insert(3);
	ms.insert(3);
	ms.insert(3);
	ms.insert(3);

	cout << "size = " << ms.size() << endl;

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	int key = 3;

	cout << ms.count(key) << endl;

	return 0;
}