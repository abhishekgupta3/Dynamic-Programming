#include <bits/stdc++.h>
using namespace std;

int MaximumSquare(vector<vector<int>>&mat, int n, int m) {
	vector<vector<int>> dp(n, vector<int>(m, 0));

	// if 1 => square matrix of size 1 is possible
	for (int i = n - 1; i >= 0; i--) {
		if (mat[i][m - 1] == 1)dp[i][m - 1] = 1;
	}
	for (int j = m - 1; j >= 0; j--) {
		if (mat[n - 1][j] == 1)dp[n - 1][j] = 1;
	}

	int ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			// dp[i][j] will be min from adjacent 2 and diagonal + 1
			int temp = min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]});
			dp[i][j] = temp + 1;
			if (dp[i][j] > ans)ans = dp[i][j];
		}
	}

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m; cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; ++j) {
			cin >> mat[i][j];
		}
	}

	cout << MaximumSquare(mat, n, m);



	return 0;
}