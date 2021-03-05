// Matrix chain multiplication
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

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
int MCMmemo(int * arr, int n, int i, int j) {

	if (dp[i][j] != -1) return dp[i][j];
	if (i >= j)return 0;

	int cost = INT_MAX;
	for (int k = i; k < j ; ++k) {
		int temp = MCMmemo(arr, n, i, k) + MCMmemo(arr, n, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		cost = min(cost, temp);
	}

	return  dp[i][j] =  cost;
}

// Matrix chain multiplication bottom up
// int MCMbottomUp(int * arr, int n, int i, int j) {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (i == j)dp[i][j] = 0;
// 		}
// 	}


// }


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

	memset(dp, -1, sizeof dp);
	// cout << MCMmemo(arr, n, i, j) << endl;

	cout << MCMbottomUp(arr, n, i, j) << endl;


	delete [] arr;


	return 0;

}