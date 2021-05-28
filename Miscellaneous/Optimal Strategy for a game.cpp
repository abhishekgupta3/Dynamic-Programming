// Optimal strategy for a game
// I/P: {5, 3, 7, 10} O/P: 15
// ***************************************************************************************
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

// Memoization
int maxAmount(int arr[], int i, int j) {

	if (dp[i][j] != -1)return dp[i][j];
	if (i >= j)return 0;
	if (i + 1 == j)return max(arr[i], arr[i + 1]);

	// we take ith coin & the opponent gives us the minimum amount from the left out coins
	int temp1 = arr[i] + min(maxAmount(arr, i + 2, j), maxAmount(arr, i + 1, j - 1));
	// we take jth coin & the opponent gives us the minimum amount from the left out coins
	int temp2 = arr[j] + min(maxAmount(arr, i + 1, j - 1), maxAmount(arr, i , j - 2));

	return dp[i][j] = max(temp1, temp2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {5, 3, 7, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0, j = n - 1;
	memset(dp, -1, sizeof dp);
	cout << maxAmount(arr, i, j) << '\n';

	return 0;
}