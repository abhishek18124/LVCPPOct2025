#include<iostream>
#include<set>

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

class ageComp {

public:

	// return true if you want a to be ordered
	// before b otherwise return false

	bool operator()(customer a, customer b) const {
		if (a.age < b.age) {
			// since we are creating a set<> based
			// on customer age in the increasing order
			// when a.age is less than b.age we want
			// a to be ordered before b in the set<>
			return true;
		}
		return false;

	}

};

int main() {

	set<customer, ageComp> s;

	s.insert(customer("areen", 18));
	s.insert(customer("himanishi", 19));
	s.insert(customer("satyam", 17));
	s.insert(customer("rimmi", 20));
	s.insert(customer("shivam", 21));

	for (customer c : s) {
		cout << c.name << " " << c.age << endl;
	}

	return 0;
}