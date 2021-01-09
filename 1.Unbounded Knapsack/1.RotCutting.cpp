// Maximize The Cut Segments:
// N = 4
// x = 2, y = 1, z = 1   O/P: 4

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// rod cut recursive T.C: O(3^n)
int maximizeTheCuts(int n, int x, int y, int z) {
	if (n == 0 ) return 0;
	if (n < 0) return INT_MIN;
	return 1 + max( maximizeTheCuts(n - x, x, y, z), max(maximizeTheCuts(n - y, x, y, z), maximizeTheCuts(n - z, x, y, z)));
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, x, y, z;
	cin >> n >> x >> y >> z;

	cout << maximizeTheCuts(n, x, y, z) << endl;

	int dp[n + 1];
	memset(dp, -1, sizeof (dp));




	return 0;

}