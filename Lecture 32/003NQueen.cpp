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

	bool isValid(int i, int j, const vector<string>& board, int n) {

		// 1. check if there is any previously placed queen
		// in the jth column

		for (int k = i - 1; k >= 0; k--) {
			if (board[k][j] == 'Q') {
				return false;
			}
		}

		// 2. check if there is any previously placed queen
		// along the right diag. of the jth column

		for (int k = i - 1, step = 1; k >= 0 and j + step < n; k--, step++) {
			if (board[k][j + step] == 'Q') {
				return false;
			}
		}

		// 3. check if there is any previously placed queen
		// along the left diag. of the jth column

		for (int k = i - 1, step = 1; k >= 0 and j - step >= 0; k--, step++) {
			if (board[k][j - step] == 'Q') {
				return false;
			}
		}


		// you can place the ith queen in the jth column of the ith row
		return true;

	}

	void f(int i, int n, vector<string>& board,
	       vector<vector<string>>& ans) {

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

			if (isValid(i, j, board, n)) {
				board[i][j] = 'Q';
				f(i + 1, n, board, ans);
				board[i][j] = '.'; // backtracking
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

		f(0, n, board, ans);

		return ans;

	}
};