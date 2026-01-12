#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		name = n;
		age = a;
		gender = g;
		credits = c;
	}
};

// return true if you want 'a' to be ordered before 'b' otherwise
// return false

bool ageCmp(customer a, customer b) {

	// if (a.age < b.age) {
	// 	// we want a to be ordered before b since we are sorting
	// 	// in increasing order based on customer age
	// 	return true;
	// }

	// return false;

	return a.age < b.age;

}

class AgeCompator {

public:

	// return true if you want a to be ordered before b
	// otherwise return false

	bool operator()(customer a, customer b) {
		return a.age < b.age;
	}

};

int main() {

	vector<customer> v;

	// customer c1("Ramanujan", 32, 'M', 1729);
	// v.push_back(c1);

	// customer c2("JC Bose", 78, 'M', 2500);
	// v.push_back(c2);

	v.push_back(customer("Ramanujan", 32, 'M', 1729));
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	for (customer& c : v) {
		cout << c.name << " " << c.age << " " << c.credits << " " << c.gender << endl;
	}

	cout << endl;

	// sort(v.begin(), v.end(), ageCmp);

	AgeCompator obj;
	sort(v.begin(), v.end(), obj);

	for (customer& c : v) {
		cout << c.name << " " << c.age << " " << c.credits << " " << c.gender << endl;
	}

	return 0;
}