#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	double ans;

	int s = 0;
	int e = n;

	while (s <= e) { // log(e-s).const // log(n).const

		int m = s + (e - s) / 2;

		if (m * m <= n) {

			ans = m;
			s = m + 1;

		} else {

			e = m - 1;

		}

	}

	int i = 1;

	double inc = 0.1;

	while (i <= p) {

		while (ans * ans <= n) {
			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc / 10;

		i = i + 1;

	}

	cout << ans << endl;

	cout << sqrt(30) << endl;

	return 0;

}