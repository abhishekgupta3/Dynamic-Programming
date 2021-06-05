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

// // Palindromic Partition Memoization T.C: O(n^3)
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

// Optmized T.C: O(n^2)
int bottomUp(string s, int n) {

	// palindrome substring matrix
	bool ps[s.length()][s.length()];
	memset(ps, 0, sizeof ps);

	//single element
	for (int i = 0; i < n; i++)ps[i][i] = 1;
	//string of len 2
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1])ps[i][i + 1] = 1;
	}

	for (int gap = 2; gap < n; gap++) {
		for (int i = 0; i < n - gap; i++) {
			int j = i + gap;
			if (s[i] == s[j] and ps[i + 1][j - 1] == 1) {
				ps[i][j] = 1;
			}
		}
	}

	// pp[i] -> number of cuts when string is from 0 to i
	int pp[s.length()];
	pp[0] = 0;

	for (int i = 1; i < n; i++) {
		// indicates the complete string is palindrome
		if (ps[0][i] == 1)pp[i] = 0;
		else {
			// when no palindrome exists considering
			// suffix staring from i
			// pp[i] will be 1 + pp[i-1]
			pp[i] = pp[i - 1] + 1;
			// finding all palindromes from  j to i
			for (int j = i - 1; j > 0; j--) {
				// found a palindrome
				if (ps[j][i] == 1) {
					pp[i] = min(pp[i], pp[j - 1] + 1);
				}
			}
		}
	}

	return pp[n - 1];
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

	// cout << PalindromePartition(s, i, j);

	cout << bottomUp(s, n) << '\n';


	return 0;
}