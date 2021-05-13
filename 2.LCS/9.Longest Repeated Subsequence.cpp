// Longest Repeated Subsequence:
// I/P: abxxxy O/P: 2
// Approach:
// find lcs, only change is when both index are same
// and string is equal, will not be considered
// ------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int n) {
	int dp[n + 1][n + 1];

	for (int i = 0; i <= n; i++)dp[i][0] = 0, dp[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i - 1] == b[j - 1] and i != j)dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][n];
}

int LongestRepeatingSubsequence(string str) {
	return lcs(str, str, str.length());
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str; cin >> str;
	cout << LongestRepeatingSubsequence(str);

	return 0;
}