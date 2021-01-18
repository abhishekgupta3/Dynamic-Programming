// Min Jumps to reach end
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
using namespace std;
typedef long long ll ;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1; //cin>>t;
	while (t--) {

		int n; cin >> n;
		int ar[n]; rep(i, 0, n) cin >> ar[i];

		// O(n^2) time complexity
		int dp[n + 1] = {0};
		for (int i = 0; i < n; ++i) {
			dp[i] = INT_MAX;
		}
		dp[0] = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= ar[i]; ++j) {
				if (i + j < n && dp[i] != INT_MAX) dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}


		rep(i, 0, n) cout << dp[i] << " ";
		cout << endl;


	}

	return 0;

}