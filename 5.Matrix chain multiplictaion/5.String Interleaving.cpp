// string interleaving
#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
bool isInterleave(string a, string b, string c, int x, int y, int z) {
	if (dp[x][y] != -1)return dp[x][y];
	if (z == 0)return true;
	bool temp1 = false, temp2 = false;
	if (x - 1 >= 0 and a[x - 1] == c[z - 1])temp1 = isInterleave(a, b, c, x - 1, y, z - 1);
	if (y - 1 >= 0 and b[y - 1] == c[z - 1])temp2 = isInterleave(a, b, c, x, y - 1, z - 1);
	return dp[x][y] = temp1 || temp2;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a, b, c; cin >> a >> b >> c;
	int x = a.length(), y = b.length(), z = c.length();
	memset(dp, -1, sizeof(dp));
	cout << isInterleave(a, b, c, x, y, z) << '\n';

	return 0;

}