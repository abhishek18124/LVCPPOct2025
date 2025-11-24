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

void printPrimes(int m) {

	for (int n = 2; n <= m; n++) {

		// check if n is a prime no. or not

		if (isPrime(n)) {

			// n is a prime no.

			cout << n << " ";

		}

	}

}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}