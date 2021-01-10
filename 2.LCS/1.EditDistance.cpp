// Edit distance
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

// Edit distance recursive O(3^n)
int ed(int x, int y, string a, string b) {
	if (x == 0) return y;
	if (y == 0) return x;

	if (a[x - 1] == b[y - 1])return ed(x - 1, y - 1, a, b);

	return 1 + min( ed(x - 1, y - 1, a, b), min( ed( x, y - 1 , a, b), ed(x - 1, y, a, b)));
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, y;
	string a, b;
	cin >> x >> y >> a >> b;

	cout << ed(x, y, a, b) << endl;

	// edit distance bottom up DP T.C: O9(x*y)

	int dp[x + 1][y + 1];
	for (int i = 0; i <= x; i++) dp[i][0] = i;
	for (int i = 0; i <= y; i++) dp[0][i] = i;

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {

			if (a[i - 1] == b[j - 1]) dp[i][j] =  dp[i - 1][j - 1];
			else dp[i][j] = 1 + min (dp[i - 1][j], min ( dp[i][j - 1], dp[i - 1][j - 1]));
		}
	}


	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++)
			cout << dp[i][j] << " "; cout << endl;
	}


	cout << dp[x][y] << endl;

	return 0;

}