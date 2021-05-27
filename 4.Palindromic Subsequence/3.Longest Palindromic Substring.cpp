// Longest Palindromic Substring + Cnt of Palindromic Substring
////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

// Top Down: Recursive + Memoization
int LPS(string s, int i, int j, int dp[][105]) {

	if (dp[i][j] != -1)return dp[i][j];

	if (i > j)return dp[i][j] = 0; // no element
	if (i == j)return dp[i][j] = 1; // one element
	if (i + 1 == j)return dp[i][j] = (s[i] == s[j]) ? 2 : 0 ; // two element

	if (s[i] == s[j]) {
		int sub_problem = LPS(s, i + 1, j - 1, dp);
		if (sub_problem == (j - i - 1))return dp[i][j] = 2 + sub_problem;
		else return dp[i][j] = max(LPS(s, i + 1, j, dp), LPS(s, i, j - 1, dp));
	}
	else {
		return dp[i][j] = max(LPS(s, i + 1, j, dp), LPS(s, i, j - 1, dp));
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s; cin >> s;
	int n = s.length();
	int i = 0, j = s.length() - 1;

	// cout << "lps length is " << LPS(s, i, j, dp) << '\n';

	// Bottom up: Tabulation. T.C: O(N^2) A.S: O(N^2)
	bool dp[105][105];
	memset(dp, 0, sizeof dp);

	int max_len = 1, cnt = 0, start = 0;
	// diagonal(one element) as 1
	for (int i = 0; i < n; ++i)	dp[i][i] = 1, cnt++;

	// two length
	for (int i = 0; i < n - 1; ++i)
		if (s[i] == s[i + 1])dp[i][i + 1] = 2, max_len = 2, cnt++, start = i;

	// three or more length
	for (int k = 2; k < n; k++) {
		for (int i = 0; i < n - k; i++) {
			int j = i + k;
			if (s[i] == s[j] and dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				if (j - i + 1 > max_len)max_len = j - i + 1, start = i;
				cnt++;
			}
		}
	}

	cout << "Max length " << max_len << "\nTotal LPS " << cnt << '\n';
	cout << s.substr(start, max_len) << '\n';



	return 0;

}