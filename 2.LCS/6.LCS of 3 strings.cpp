// LCS of 3 strings
#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a, b, c; cin >> a >> b >> c;

	int dp[105][105][105];
	memset(dp, -1, sizeof dp);

	for (int j = 0; j <= b.length(); j++) {
		for (int k = 0; k <= c.length(); k++) {
			dp[0][j][k] = 0;
		}
	}
	for (int i = 0; i <= a.length(); i++) {
		for (int k = 0; k <= c.length(); k++) {
			dp[i][0][k] = 0;
		}
	}
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			dp[i][j][0] = 0;
		}
	}

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			for (int k = 1; k <= c.length(); k++) {

				if (a[i - 1] == b[j - 1] and b[j - 1] == c[k - 1]) {
					dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
				}
				else {
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}
	cout << dp[a.length()][b.length()][c.length()] << '\n';

	return 0;

}