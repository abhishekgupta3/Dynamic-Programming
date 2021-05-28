// Count Palindromic Subsequences
// I/P: abcd O/P: 4

#include <bits/stdc++.h>
using namespace std;

// Recursive
int cntPS(string s, int i, int j) {
	if (i == j)return 1;
	if (i > j)return 0;
	if (s[i] == s[j])return 1 + cntPS(s, i, j - 1) + cntPS(s, i + 1, j);

	return cntPS(s, i, j - 1) + cntPS(s, i + 1, j) - cntPS(s, i + 1, j - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s; cin >> s;
	int n = s.length();

	// Bottom up: T.C: O(N*N) A.S: O(N*N)
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof dp);

	// filling diagonal
	for (int i = 0; i < n; ++i)dp[i][i] = 1;

	for (int k = 2; k <= n; ++k) {
		for (int i = 0; i <= n - k; ++i)	{
			int j = k + i - 1;
			if (s[i] == s[j]) dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
			else dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}

	cout << dp[0][n - 1] << '\n';

	return 0;
}