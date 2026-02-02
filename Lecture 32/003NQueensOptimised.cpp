/*

https://leetcode.com/problems/n-queens/

N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example
	Input : N = 4
	Output:
			_ Q _ _	     _ _ Q _
	        _ _ _ Q      Q _ _ _
	        Q _ _ _      _ _ _ Q
	        _ _ Q _      _ Q _ _

	        [1, 3, 0, 2] [2, 0, 3, 1]

Constraint:
	1<=n<=10

*/

class Solution {
public:

	void f(int i, int n, vector<string>& board,
	       vector<vector<string>>& ans, vector<bool>& columnStatus,
	       vector<bool>& rightDiagStatus,
	       vector<bool>& leftDiagStatus) {

		// base case
		if (i == n) {
			ans.push_back(board);
			return;
		}

		// recursive case

		// f(i) : take decisions for the remaining queens {qi, qi+1, ...qn-1}

		// decide for the ith queen

		for (int j = 0; j < n; j++) {

			// I am trying to place the ith queen
			// in the jth column of the ith row

			if (columnStatus[j] == false and rightDiagStatus[i + j] == false and leftDiagStatus[(i - j) + (n - 1)] == false) {
				board[i][j] = 'Q';
				columnStatus[j] = true;
				rightDiagStatus[i + j] = true;
				leftDiagStatus[(i - j) + (n - 1)] = true;
				f(i + 1, n, board, ans, columnStatus, rightDiagStatus, leftDiagStatus);
				board[i][j] = '.'; // backtracking
				columnStatus[j] = false; // backtracking
				rightDiagStatus[i + j] = false; // backtracking
				leftDiagStatus[(i - j) + (n - 1)] = false;
			}

		}

	}

	vector<vector<string>> solveNQueens(int n) {

		vector<string> board;
		for (int i = 1; i <= n; i++) {
			string row(n, '.');
			board.push_back(row);
		}

		vector<vector<string>> ans;

		vector<bool> columnStatus(n, false);
		vector<bool> rightDiagStatus(2 * n - 1, false);
		vector<bool> leftDiagStatus(2 * n - 1, false);

		f(0, n, board, ans, columnStatus, rightDiagStatus, leftDiagStatus);

		return ans;

	}
};