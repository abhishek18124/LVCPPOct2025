class Solution {
public:

	// time : O(n)
	// space: O(n)

	vector<int> asteroidCollision(vector<int>& asteroids) {

		stack<int> s;

		for (int ast : asteroids) {
			if (ast < 0 and !s.empty() and s.top() > 0) {
				// collision(s) will happen
				bool flag = true; // assume ast will survive collisions
				while (!s.empty() and s.top() > 0) {
					if (abs(ast) > s.top()) {
						// s.top() will be destroyed
						s.pop();
					} else if (s.top() > abs(ast)) {
						// ast will be destroyed
						flag = false;
						break;
					} else {
						// abs(ast) is equal to s.top()
						// both ast and s.top() will be destroyed
						s.pop();
						flag = false;
						break;
					}
				}
				if (flag) {
					// ast has indeed survived collisions so track ast
					s.push(ast);
				}
			} else {
				s.push(ast);
			}
		}

		vector<int> ans;
		while (!s.empty()) {
			ans.push_back(s.top());
			s.pop();
		}

		reverse(ans.begin(), ans.end());
		return ans;

	}
};