// Optimal Bst: Find the minimum cost to construct a BST

#include <iostream>
#include <climits>
using namespace std;

int OptimalBST(int n, int freq[]) {

	int dp[n][n];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)	dp[i][j] = 0;
	}

	for (int gap = 0; gap < n; gap++) {
		for (int i = 0, j = gap; j < n; j++, i++) {
			if (gap == 0) {
				dp[i][j] = freq[i];
			}
			if (gap == 1) {
				int f1 = freq[i], f2 = freq[j];
				dp[i][j] = min(f1 + 2 * f2, f1 * 2 + f2);
			}
			else {
				int sum = 0;
				for (int k = i; k <= j; k++)sum += freq[k];

				int temp1 = 0, temp2 = 0, mn = INT_MAX;
				for (int k = i; k <= j; k++) {

					temp1 = (k - 1 >= 0) ? dp[i][k - 1] : 0;
					temp2 = (k + 1 < n) ? dp[k + 1][j] : 0;

					mn = min(mn, temp1 + temp2 + sum);
				}
				dp[i][j] = mn;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}

	return dp[0][n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int keys[n], freq[n];
	for (int i = 0; i < n; i++)cin >> keys[i];
	for (int i = 0; i < n; i++)cin >> freq[i];

	cout << OptimalBST(n, freq);

	return 0;
}