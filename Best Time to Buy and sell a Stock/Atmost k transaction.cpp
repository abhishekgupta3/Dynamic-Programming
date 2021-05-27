// Best Time to buy and sell a stock: atmost k Transaction
// Approach: dp table of [k+1][n+1] size. can be optimized to work in O(N^2)
////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

// T.C: O(N^3) A.S: O(N*K)
int profit(vector<int> arr, int k) {
	int n = arr.size();
	int dp[k + 1][n + 1];
	memset(dp, -1, sizeof dp);

	for (int i = 0; i <= n; i++)dp[0][i] = 0;
	for (int i = 0; i <= k; i++)dp[i][0] = 0;

	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			int mx = INT_MIN;
			for (int  l = 0; l < j; ++l) {
				mx = max(mx, dp[i - 1][l] + arr[j - 1] - arr[l]);
			}

			dp[i][j] = max(dp[i][j - 1], mx);
		}

	}

	return dp[k][n];
}

// Optimized T.C: O(N*K) A.S: O(N*K)
int profit_optimized(vector<int> arr, int k) {
	int n = arr.size();
	int dp[k + 1][n + 1];
	memset(dp, -1, sizeof dp);

	for (int i = 0; i <= n; i++)dp[0][i] = 0;
	for (int i = 0; i <= k; i++)dp[i][0] = 0;

	for (int i = 1; i <= k; ++i) {
		int mx = INT_MIN;
		for (int j = 1; j <= n; ++j) {
			mx = max(mx, dp[i - 1][j - 1] - arr[j - 1]);
			dp[i][j] = max(dp[i][j - 1], mx + arr[j - 1]);
		}

	}

	return dp[k][n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> v {10, 22, 5, 75, 65, 80};
	int k = 3;
	cout << profit_optimized(v, k);


	return 0;
}