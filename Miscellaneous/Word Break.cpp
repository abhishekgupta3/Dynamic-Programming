// Word Break
// I.P: {game,theory} s = gametheory O.P: true
//**********************************************************************************
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int>dp;

int wordBreak(string s, vector<string> &v) {
	if (s.length() == 0)return 1;
	if (dp[s])return dp[s];

	for (int i = 1; i <= s.length(); i++) {
		string a = s.substr(0, i);
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == a and wordBreak(s.substr(i), v) == 1)return dp[s] = 1;
		}
	}
	return dp[s] = 0;
}

int main() {
	int n; cin >> n;
	vector<string> dict;
	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		dict.push_back(S);
	}
	string s; cin >> s;
	cout << wordBreak(s, dict) << "\n";

	return 0;
}
