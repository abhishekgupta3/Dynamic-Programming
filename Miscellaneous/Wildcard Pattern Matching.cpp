// Wildcard Pattern Matching
// *************************************************************************************
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

bool wildcard(string& s, string& p, int i, int j) {

	//base case
	if (i == s.length() and j == p.length())return 1;
	// pattern end
	if (j == p.length())return 0;
	// string end
	if (i == s.length()) {
		for (int k = j; k < p.length(); k++) {
			if (p[k] != '*')return false;
		}
		return true;
	}

	// Memoization
	if (dp[i][j] != -1) return dp[i][j];

	if (s[i] == p[j] || p[j] == '?') {
		dp[i][j] = wildcard(s, p, i + 1, j + 1);
	}
	else if (p[j] == '*') {
		dp[i][j] = wildcard(s, p, i + 1, j) || wildcard(s, p, i, j + 1);
	}
	else dp[i][j] = 0;

	return dp[i][j];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str, pat; cin >> str >> pat;
	// resize the dp array
	dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));

	cout << wildcard(str, pat, 0, 0);

	return 0;
}