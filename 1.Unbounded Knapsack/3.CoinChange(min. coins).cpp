// coin change min no. of coins
// coins[] = {25, 10, 5}, V = 30 O/P: 2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// coin change recursive T.C: O(2^n)
int coinChangeRec(int ar[] , int n, int sum) {
	if (sum == 0)return 0;

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (ar[i] <= sum) {
			int subProb = coinChangeRec(ar, n, sum - ar[i]);
			if (subProb != INT_MAX && subProb + 1 < ans) ans =  subProb + 1;
		}
	}

	return ans;
}

// coin change memoization T.C: O(n*sum) A.S: O(sum)
int coinChangeMemo(int ar[] , int n, int sum, int dp[1005]) {

	if (sum == 0)return 0;
	if (dp[sum] != -1) return dp[sum];


	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (ar[i] <= sum) {
			int subProb = coinChangeMemo(ar, n, sum - ar[i], dp);
			if (subProb != INT_MAX && subProb + 1 < ans) ans =  subProb + 1;
		}
	}
	dp[sum] = ans;
	return ans;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, sum;
	cin >> n >> sum;
	int ar[n];

	for (int i = 0; i < n; ++i)	{
		cin >> ar[i];
	}

	cout << coinChangeRec(ar, n, sum) << endl;

	// dp[i] stores min coin to make sum i
	int dp[sum + 1];
	memset(dp, -1, sizeof dp);
	cout << coinChangeMemo(ar, n, sum, dp) << endl;

// coin change dp solution( bottom up) T.C : O(n*sum)  A.S : O(sum)
	memset(dp, -1, sizeof dp);

	dp[0] = 0;
	for (int i = 1; i <= sum; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (ar[j] <= i) {
				int subProb = dp[i - ar[j]];
				if (subProb != INT_MAX && subProb + 1 < dp[i]) dp[i] =  subProb + 1;
			}
		}
	}

	cout << dp[sum] == INT_MAX ? -1 : dp[sum]  << " ";

	// for (int i = 0; i <= sum; i++) {
	// 	cout << dp[i] << " ";
	// }


	return 0;

}