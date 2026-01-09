#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	int n;
	cin >> n;

	int p;
	cin >> p;

	double ans;

	double s = 0;
	double e = n;

	for (int i = 1; i <= 70; i++) {

		double m = s + (e - s) / 2;

		if (m * m <= n) {

			ans = m;
			s = m + 1e-16;

		} else {

			e = m - 1e-16;

		}

	}

	cout << setprecision(p) << fixed;
	cout << ans << endl;

	return 0;
}