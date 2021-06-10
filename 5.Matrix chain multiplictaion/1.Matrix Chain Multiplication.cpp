// Matrix chain multiplication
// I.P: 1 2 3 4 3    O.P: 30

#include <bits/stdc++.h>
using namespace std;

// Matrix chain multiplication recursive
int MCMRec(int * arr, int n, int i, int j) {

	if (i >= j)return 0;

	int cost = INT_MAX;
	for (int k = i; k < j ; ++k) {
		int temp = MCMRec(arr, n, i, k) + MCMRec(arr, n, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		cost = min(cost, temp);
	}

	return cost;
}

// Matrix chain multiplication memoization
int MCMmemo(int * arr, int n, int i, int j, int dp[][105]) {

	if (dp[i][j] != -1) return dp[i][j];
	if (i >= j)return 0;

	int cost = INT_MAX;
	for (int k = i; k < j ; ++k) {
		int temp = MCMmemo(arr, n, i, k, dp) + MCMmemo(arr, n, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
		cost = min(cost, temp);
	}

	return  dp[i][j] =  cost;
}

// Matrix chain multiplication bottom up
int MCMbottomUp(int * arr, int n) {
	int dp[n - 1][n - 1];
	memset(dp, 0, sizeof dp);

	for (int gap = 0; gap < n - 1; gap++) {
		for (int i = 0, j = gap; j < n - 1; j++, i++) {

			if (gap == 0)dp[i][j] = 0;
			else if (gap == 1) {
				dp[i][j] = arr[i] * arr[j] * arr[j + 1];
			}
			else {
				int temp = INT_MAX;
				for (int k = i; k < j; k++) {
					// dp -> i to k left half , k+1 to j right half
					int leftcost = dp[i][k];
					int rightcost = dp[k + 1][j];
					int multiplicationcost = arr[i] * arr[k + 1] * arr[j + 1];
					temp = min(temp, leftcost + rightcost + multiplicationcost);
				}

				dp[i][j] = temp;
			}
		}
	}

	return dp[0][n - 2];

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int * arr = new int[n];
	for (int i = 0; i < n; i++)cin >> arr[i];

	int i = 1, j = n - 1;
	cout << MCMRec(arr, n, i, j) << endl;


	int dp[105][105];
	memset(dp, -1, sizeof dp);
	cout << MCMmemo(arr, n, i, j, dp) << endl;


	cout << MCMbottomUp(arr, n) << endl;


	delete [] arr;

	return 0;
}