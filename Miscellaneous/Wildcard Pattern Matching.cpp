// Wildcard Pattern Matching
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

bool wildcard(string s, string p, int i, int j, int n, int m) {
	if (i == n and j == m)return 1;
	if (j == m)return 0;

	if (s[i] == p[j])return wildcard(s, p, i + 1, j + 1, n, m);
	else if (p[j] == '?') return wildcard(s, p, i + 1, j + 1, n, m);
	else if (p[j] == '*') {
		// * replaced with empty sequence
		bool a = wildcard(s, p, i, j + 1, n, m);
		// * replaced with s[i]
		bool b = wildcard(s, p, i + 1, j + 1, n, m);
		// * replaced with s[i] followed by *
		bool c = wildcard(s, p, i + 1, j, n, m);
		return a || b || c;
	}
	else return 0;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str, pat; cin >> str >> pat;
	int n = str.length(), m = pat.length();
	cout << wildcard(str, pat, 0, 0, n, m);

	return 0;
}