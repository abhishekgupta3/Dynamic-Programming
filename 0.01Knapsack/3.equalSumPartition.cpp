// equal sum partition:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n , sum = 0;
	cin >> n ;

	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i] , sum += arr[i];
	if (sum % 2 != 0) {
		return 0;
	}
	else {
		sum /= 2;
		int dp[n + 1][sum + 1];

		// equal sum partition: solution( bottom up) T.C : O(n*sum)  A.S : O(n*sum)
		for (int i = 0; i <= sum; i++) dp[0][i] = 0;
		for (int i = 0; i <= n; i++) dp[i][0] = 1;

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

		return dp[n][sum];
	}

	return 0;

}