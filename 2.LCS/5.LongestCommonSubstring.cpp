// Longest Common Substring:
// instead of taking max in LCS replace that with 0 and ans would be maxium result obtained
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

// lcs recursive O(2^n)
int lcs(int x, int y, string a, string b, int ans) {
	if (x == 0 || y == 0) return 0;
	if (a[x - 1] == b[y - 1])ans = lcs(x - 1, y - 1, a, b, ans + 1);
	ans = max(ans, max(lcs(x, y - 1, a, b, 0), lcs(x - 1, y, a, b, 0)));
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, y;
	string a, b;
	cin >> x >> y >> a >> b;
	int ans = 0;
	cout << lcs(x, y, a, b, ans) << endl;

	int dp[105][105];
	memset(dp, -1, sizeof dp);

	ans = 0;

	// lcs bottom up O(x*y)
	for (int i = 0; i <= x; i++) dp[i][0] = 0;
	for (int i = 0; i <= y; i++) dp[0][i] = 0;

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {

			if (a[i - 1] == b[j - 1]) {
				dp[i][j] =  1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	cout << ans << endl;

	return 0;

}