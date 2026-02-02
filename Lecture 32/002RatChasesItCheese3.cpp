#include<iostream>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == m or j == n or i == -1 or j == -1) {
		return;
	}

	if (maze[i][j] == 'X') {
		return;
	}

	if (i == m - 1 and j == n - 1) {
		// print the path
		path[i][j] = '1';
		for (int ii = 0; ii < m; ii++) {
			for (int jj = 0; jj < n; jj++) {
				cout << path[ii][jj] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return;
	}

	// recursive case

	path[i][j] = '1';
	maze[i][j] = 'X';

	for (int k = 0; k < 4; k++) {
		f(maze, path, m, n, i + dx[k], j + dy[k]);
	}

	path[i][j] = '0';
	maze[i][j] = '0';

}

int main() {

	char maze[][10] = {
		"0X00",
		"000X",
		"X0X0",
		"X00X",
		"XX00"
	};

	char path[][10] = {
		"0000",
		"0000",
		"0000",
		"0000",
		"0000"
	};

	int m = 5;
	int n = 4;

	f(maze, path, m, n, 0, 0);

	return 0;
}
