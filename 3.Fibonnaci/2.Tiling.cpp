// 2*1 Tiling: find no. of ways to use 2*1 or 1*2 tiles to fill up 2*N Tile
// ---------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// tiling recursive
int Tiling(int n) {
	if (n <= 1)return 1;
	if (n == 2)return 2;
	return Tiling(n - 1) + Tiling(n - 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	cout << Tiling(n);

	return 0;

}