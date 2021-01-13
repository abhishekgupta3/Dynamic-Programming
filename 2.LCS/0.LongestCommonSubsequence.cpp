// Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

// lcs recursive O(2^n)
int lcs(int x, int y, string a, string b) {
	if (x == 0 || y == 0) return 0;
	if (a[x - 1] == b[y - 1])return 1 + lcs(x - 1, y - 1, a, b);

	return max(lcs(x - 1, y, a, b), lcs(x, y - 1, a, b));
}

// lcs memosization O(x*y)
int lcsMemo(int x, int y, string a, string b, int dp[][105]) {
	if (x == 0 || y == 0) dp[x][y] = 0;
	if (dp[x][y] != -1) return dp[x][y];
	if (a[x - 1] == b[y - 1]) dp[x][y] =  1 + lcsMemo(x - 1, y - 1, a, b, dp);
	else
		dp[x][y] = max(lcsMemo(x - 1, y, a, b, dp), lcsMemo(x, y - 1, a, b, dp));
	return dp[x][y];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, y;
	string a, b;
	cin >> x >> y >> a >> b;

	cout << lcs(x, y, a, b) << endl;

	int dp[105][105];
	memset(dp, -1, sizeof dp);

	cout << lcsMemo(x, y, a, b, dp) << endl;

	// lcs bottom up O(x*y)
	for (int i = 0; i <= x; i++) dp[i][0] = 0;
	for (int i = 0; i <= y; i++) dp[0][i] = 0;

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {

			if (a[i - 1] == b[j - 1]) dp[i][j] =  1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[x][y] << endl;

	return 0;

}