// rod cutting
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//  recursive T.C: O(2^n)
int Rec(int len[] , int n, int price[], int totalLen) {
	if (n == 0 ) return 0;
	if (len[n - 1] > totalLen) {
		return Rec(len, n - 1, price, totalLen);
	}
	return max(price[n - 1] + Rec(len, n , price, totalLen - len[n - 1]), Rec(len,  n - 1, price, totalLen));
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int price[n], len[n];

	for (int i = 0; i < n; i++) cin >> price[i];
	for (int i = 0; i < n; i++) len[i] = i + 1;
	int totalLen = n;

	cout << Rec(len, n, price, totalLen) << endl;

	//  dp solution( bottom up) T.C : O(n*w)  A.S : O(n*w)
	int t[n + 1][n + 1];
	memset(t, -1, sizeof t);
	for (int i = 0; i <= n; i++) t[i][0] = 0;
	for (int i = 0; i <= totalLen; i++) t[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (len[i - 1] > j) {
				t[i][j] = t[i - 1][j];
			}
			else {
				t[i][j] = max(price[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
			}
		}
	}

	cout << t[n][n] << endl;


	return 0;

}