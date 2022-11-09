// divide the numbers into two subsets S1 and S2 such that the
// absolute difference between their sums is minimum.
#include <bits/stdc++.h>
using namespace std;

int MinimumSubsetDifference(int A[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) sum += A[i];

	// dp[i][j] stores if sum j can be formed with subset from 0 to i
	bool dp[n + 1][sum + 1];

	for (int j = 0; j <= sum; j++)dp[0][j] = 0;
	for (int i = 0; i <= n; i++)dp[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (A[i - 1] > j)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
		}
	}

	int mn = INT_MAX;
	// traversing the last row of dp
	for (int i = 0; i <= sum / 2; i++) {
		if (dp[n][i] == 1) mn = min(mn, sum - 2 * i);
	}

	return mn;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {1, 6, 11, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << MinimumSubsetDifference(arr, n);

	return 0;
}
