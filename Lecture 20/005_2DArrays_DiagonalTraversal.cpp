/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void printDiag(int mat[][10], int m, int n, int i, int j) {

	// print the diagonal that starts at (i, j)

	while (i < m and j < n) { // no. of iterations = length of the diag that starts at the i,jth index = min(m-i, n-j)
		cout << mat[i][j] << " ";
		i++;
		j++;
	}

	cout << endl;

}

void diagonalTraversal(int mat[][10], int m, int n) {

	// iterate over the starting points of the diagonals in the matrix

	for (int j = 0; j < n; j++) {
		// print the diagonal that starts at (0, j)
		printDiag(mat, m, n, 0, j);
	}

	for (int i = 1; i < m; i++) {
		// print the diagonal that starts at (i, 0)
		printDiag(mat, m, n, i, 0);
	}

}

int main() {

	int mat[10][10] = {
		{11, 12, 13, 14},
		{15, 16, 17, 18},
		{19, 20, 21, 22}
	};

	int m = 3;
	int n = 4;

	diagonalTraversal(mat, m, n);

	return 0;
}