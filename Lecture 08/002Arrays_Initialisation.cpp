#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};
	int n = 5;

	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	int B[] = {100, 200, 300};
	int m = sizeof(B) / sizeof(int);

	cout << m << endl;

	for (int i = 0; i < m; i++) {
		cout << B[i] << " ";
	}

	cout << endl;

	int C[5] = {1000, 2000};

	for (int i = 0; i < 5; i++) {
		cout << C[i] << " ";
	}

	cout << endl;

	int D[5] = {0};

	for (int i = 0; i < 5; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	int E[5] = {};

	for (int i = 0; i < 5; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	int F[5];

	memset(F, 0, sizeof(F));

	for (int i = 0; i < 5; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	int G[5];

	memset(G, -1, sizeof(G));

	for (int i = 0; i < 5; i++) {
		cout << G[i] << " ";
	}

	cout << endl;

	int H[5];

	// memset(H, 10, sizeof(H));

	for (int i = 0; i < 5; i++) {
		H[i] = 10;
	}

	for (int i = 0; i < 5; i++) {
		cout << H[i] << " ";
	}

	cout << endl;

	return 0;

}