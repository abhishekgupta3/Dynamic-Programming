// Count Palindromic Subsequences
// I/P: abcd O/P: 4

#include <bits/stdc++.h>
using namespace std;

int cntLPS(string a, string b, int n, int m) {
	if (m == 0 || n == 0)return 0;
	if (a[n - 1] == b[m - 1])return 1 + cntLPS(a, b, n - 1, m - 1);

	return cntLPS(a, b, n - 1, m) + cntLPS(a, b, n, m - 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s; cin >> s;
	string r = s;
	reverse(s.begin(), s.end());

	cout << cntLPS(r, s, r.length(), s.length()) << '\n';


	return 0;

}