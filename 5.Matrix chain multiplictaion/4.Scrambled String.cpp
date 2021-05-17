// Scrambled String
// Given 2 strings return whether they are scrambled
// I/P: coder ocder O/P: true
// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// Scrambled String recursive
bool scrambledString(string a, string b) {
	int n = a.length();
	if (a == b || n == 0)return true;

	for (int k = 1; k < n; k++) {
		// when there is a swap
		if (scrambledString(a.substr(0, k), b.substr(n - k, k)) and scrambledString(a.substr(k, n - k), b.substr(0, n - k))) return true;
		// no swap
		if (scrambledString(a.substr(0, k), b.substr(0, k)) and scrambledString(a.substr(k, n - k), b.substr(k, n - k))) return true;
	}

	return false;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string a, b; cin >> a >> b;
	int n = a.length(), m = b.length();

	if (n != m)cout << "Not Scrambled" << '\n';
	cout << scrambledString(a, b);

	return 0;

}