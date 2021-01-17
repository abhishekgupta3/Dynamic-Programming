// Maximum sum increasing subsequence
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	int * ar = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int * dp = new int[n];

	// Maximum sum increasing subsequence bottom up O(n*n)
	for (int i = 0; i < n; i++) {
		dp[i] = ar[i];
		for (int j = 0; j < i; j++) {
			if (ar[j] < ar[i]) dp[i] = max(dp[i], dp[j] + ar[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	cout << *max_element(dp, dp + n) << endl;

	return 0;

}