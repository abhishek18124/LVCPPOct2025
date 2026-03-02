/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:
	string name;
	int age;

	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

class ageCmp {

public:

	// return false if you want a to given more priority
	// than b otherwise return true

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			// since a.age is less than b.age and we are building a minHeap
			// based on age, we want to give customer a more priority than
			// customer b therefore we return false;
			return false;
		} else {
			return true;
		}
	}

};

int main() {

	priority_queue<customer, vector<customer>, ageCmp> minHeap;

	minHeap.push(customer("tushar", 19));
	minHeap.push(customer("kanwaljeet", 18));
	minHeap.push(customer("himanshi", 20));
	minHeap.push(customer("hajira", 21));
	minHeap.push(customer("aryan", 17));

	while (!minHeap.empty()) {
		customer c = minHeap.top();
		minHeap.pop();
		cout << c.name << " " << c.age << endl;
	}



	return 0;
}