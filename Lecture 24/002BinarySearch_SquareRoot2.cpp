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

	while (e - s > 1e-7) {

		double m = s + (e - s) / 2;

		if (m * m <= n) {

			ans = m;
			s = m + 1e-7;

		} else {

			e = m - 1e-7;

		}

	}

	cout << setprecision(p) << fixed;
	cout << ans << endl;

	return 0;
}