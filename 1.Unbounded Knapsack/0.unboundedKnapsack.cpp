// unbounded knapsack
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005][1005];


// unboundedknapsack recursive T.C: O(2^n)
int knapsackRec(int val[] , int w[], int n, int W) {
	if (n == 0 || W == 0) {
		return 0;
	}
	if (w[n - 1] > W) {
		return knapsackRec(val, w, n - 1, W);
	}
	return max(val[n - 1] + knapsackRec(val, w, n , W - w[n - 1]), knapsackRec(val, w, n - 1, W));
}

// unboundedknapsack memoization T.C: O(n*W) A.S: O(n*W)
int knapsackMemo(int val[] , int wt[], int n, int W, int dp[][1005]) {
	if (n == 0 || W == 0) return 0;
	if (dp[n][W] != -1) return dp[n][W];

	if (wt[n - 1] > W) {
		dp[n][W] = knapsackMemo(val, wt, n - 1, W, dp);
	}
	else {
		dp[n][W] = max(val[n - 1] + knapsackMemo(val, wt, n, W - wt[n - 1], dp), knapsackMemo(val, wt, n - 1, W, dp));
	}
	return dp[n][W];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, w;
	cin >> n >> w;

	int val[n], wt[n];

	for (int i = 0; i < n; i++)
		cin >> val[i];

	for (int i = 0; i < n; i++)
		cin >> wt[i];
	memset(dp, -1, sizeof(dp));

	cout << knapsackMemo(val, wt, n, w, dp) << endl;

	// unboundedknapsack dp solution( bottom up) T.C : O(n*w)  A.S : O(n*w)
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int i = 0; i <= w; i++) dp[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (wt[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
			}
		}
	}

	cout << dp[n][w] << endl;





	return 0;

}