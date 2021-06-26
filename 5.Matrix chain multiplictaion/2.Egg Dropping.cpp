//  EGG DROP: minimize the number of trials in worst case
#include <bits/stdc++.h>
using namespace std;

int dp[205][205];

int eggRecursive(int n, int k) {
	if (k == 1)return n; // no. of eggs is 1
	if (n == 1 || n == 0 )return n; // floors = 0 or 1

	int ans = INT_MAX;
	for (int x = 1; x <= n; ++x) {
		// taking max for worst case
		int temp = 1 + max(eggRecursive(x - 1, k - 1), eggRecursive(n - x, k));
		// taking min for minimum number of attempts
		ans = min(ans, temp);
	}
	return ans;
}

int eggMemo(int n, int k) {
	if (k == 1)return n; // no. of eggs is 1
	if (n == 1 || n == 0 )return n; // floors = 0 or 1

	if (dp[n][k] != -1) return dp[n][k];

	int ans = INT_MAX;
	for (int x = 1; x <= n; ++x) {
		// taking max for worst case
		int temp = 1 + max(eggMemo(x - 1, k - 1), eggMemo(n - x, k));
		// taking min for minimum number of attempts
		ans = min(ans, temp);
	}
	return dp[n][k] = ans;
}

// Optimized T.C : O(k*n*logN)
int eggDrop(int n, int k, vector<vector<int>>&dp) {

	if (k == 1)return n;
	if (n == 1 || n == 0)return n;

	if (dp[n][k] != -1)return dp[n][k];

	int ans = INT_MAX, low = 0, high = n;

	// binary search
	while (low <= high) {
		int mid = low + (high - low) / 2;

		int bottom = eggDrop(mid - 1, k - 1, dp);
		int top = eggDrop(n - mid, k, dp);

		int temp = 1 + max(bottom, top);

		//since, temp is needed to be maximized
		if (bottom < top)low = mid + 1;
		else high = mid - 1;

		ans = min(ans, temp);
	}
	return dp[n][k] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k; cin >> n >> k; // n floors k eggs
	cout << eggRecursive(n, k) << '\n';

	// Top down
	memset(dp, -1, sizeof dp);
	cout << eggMemo(n, k) << '\n';

	// optimized
	vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
	cout << eggDrop(n, k, dp);

	// bottom down T.C: O(eggs*floors*floors) = O(k*n^2)
	int mat[205][205]; //eggs X floors (k*n)
	memset(mat, 0, sizeof mat);

	for (int i = 1; i <= n; i++) {
		mat[1][i] = i;
	}
	for (int i = 1; i <= k; i++) mat[i][1] = 1;

	for (int i = 2; i <= k; i++) {
		for (int j = 2; j <= n; j++) {

			mat[i][j] = INT_MAX;
			for (int x = 1; x <= j; ++x) {
				int temp = 1 + max(mat[i - 1][x - 1], mat[i][j - x]);
				mat[i][j] = min(mat[i][j], temp);
			}

		}
	}

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << mat[k][n] << '\n';


	return 0;
}