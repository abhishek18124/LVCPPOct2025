#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			// you've found a factor of n in the range 2 to sqrt(n)
			// therefore n is not a prime no.
			return false;
		}
	}

	// n is a prime no.
	return true;

}

int main() {

	int n;
	cin >> n;

	isPrime(n) ? cout << "prime" << endl : cout << "not prime" << endl;

	return 0;
}