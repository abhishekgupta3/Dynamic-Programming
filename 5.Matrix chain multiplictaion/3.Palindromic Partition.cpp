// Palindromic Partition
// I/P: ababbbabbababa O/P: 3 (a , babbbab , b, ababa)

#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool isPaindrome(string s, int i, int j) {
	if (i >= j)return true;
	if (s[i] != s[j])return false;
	return isPaindrome(s, i + 1, j - 1);
}

// Palindromic Partition Memoization T.C: O(n^3)
int PalindromePartition(string s, int i, int j) {

	if (dp[i][j] != -1)return dp[i][j];
	if (i >= j)return 0;
	if (isPaindrome(s, i, j))return 0;

	int ans = INT_MAX;

	for (int k = i; k < j; k++) {
		int temp1 = PalindromePartition(s, i, k);
		int temp2 = PalindromePartition(s, k + 1, j);
		ans = min(ans, temp1 + temp2 + 1);
	}

	return dp[i][j] = ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s; cin >> s;
	int n = s.length();

	int i = 0, j = n - 1;
	memset(dp, -1, sizeof dp);
	cout << PalindromePartition(s, i, j);

	return 0;

}