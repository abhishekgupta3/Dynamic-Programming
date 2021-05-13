// Subset sum :
// Given a set of non-negative integers, and a sum, determine if there is a subset of the given set with sum equal to given sum.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005][1005];


// subset sum recursive T.C: O(2^n)
bool subsetRec(int arr[] , int n, int sum) {
	if (sum == 0 )return 1;
	if (n == 0 ) return 0;

	if (arr[n - 1] > sum) {
		return subsetRec(arr,  n - 1, sum);
	}
	return (subsetRec(arr,  n - 1, sum - arr[n - 1]) || subsetRec(arr,  n - 1, sum ));
}

// subset memoization T.C: O(n*sum) A.S: O(n*sum)
int subsetMemo(int arr[] , int n, int sum, int dp[][1005]) {
	if (sum == 0 ) return 1;
	if (n == 0 ) return 0;

	if (dp[n][sum] != -1) return dp[n][sum];

	if (arr[n - 1] > sum) {
		dp[n][sum] = subsetMemo(arr, n - 1, sum, dp);
	}
	else {
		dp[n][sum] =  subsetMemo(arr, n - 1, sum - arr[n - 1], dp) || subsetMemo(arr, n - 1, sum, dp);
	}
	return dp[n][sum];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n , sum;
	cin >> n >> sum ;

	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	// subset dp solution( bottom up) T.C : O(n*sum)  A.S : O(n*sum)
	for (int i = 0; i <= sum; i++) dp[0][i] = 0; // top row all 0
	for (int i = 0; i <= n; i++) dp[i][0] = 1; // top col all 1 dp[0][0]=1

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = ( dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
			}
		}
	}

	cout << dp[n][sum] << endl;





	return 0;

}