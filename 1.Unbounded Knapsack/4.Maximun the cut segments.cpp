// maximum rod cut
#include <bits/stdc++.h>
using namespace std;

int dp[100005];

// memoization T.C: O(N) A.S: O(N)
int memo(int n, int x, int y, int z) {
	if (dp[n] != -1)return dp[n];
	if (n == 0)return 0;

	int a = INT_MIN, b = INT_MIN, c = INT_MIN;
	if (n >= x)a = memo(n - x, x, y, z);
	if (n >= y)b = memo(n - y, x, y, z);
	if (n >= z)c = memo(n - z, x, y, z);

	dp[n] = 1 + max(a, max(b, c));
	return dp[n];

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, x, y, z; cin >> n >> x >> y >> z;

	for (int i = 0; i <= n; i++) dp[i] = -1;
	dp[0] = 0;
	cout << memo(n, x, y, z)  << '\n';

	// top down
	for (int i = 0; i <= n; i++) dp[i] = -1;
	dp[0] = 0;

	for (int i = 0; i <= n; ++i) {
		if (i + x <= n)dp[i + x] = max(dp[i + x], dp[i] + 1);
		if (i + y <= n)dp[i + y] = max(dp[i + y], dp[i] + 1);
		if (i + z <= n)dp[i + z] = max(dp[i + z], dp[i] + 1);
	}

	cout << dp[n] << '\n';




	return 0;

}