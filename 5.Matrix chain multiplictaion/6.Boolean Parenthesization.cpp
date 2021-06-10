// Evaluate Boolean Parenthesis
// IP: T|T&F^T   OP: 4
#include <bits/stdc++.h>
using namespace std;

/*
	Expression: a (operator) b

OR:
	True  -> lt*rt + lf*rt +lt*rf
	False -> lf*rf
AND:
	True  -> lt*rt
	False -> lf*rf + lf*rt +lt*rf
XOR:
	True  -> lf*rt + lt*rf
	False -> lf*rf + lt*rt

*/

int Evaluate(string str1, string str2) {
	int n = str1.length();
	int dpt[n][n];
	int dpf[n][n];

	memset(dpt, 0, sizeof dpt);
	memset(dpf, 0, sizeof dpf);

	for (int gap = 0; gap < n; gap++) {
		for (int i = 0, j = gap; j < n; i++, j++) {
			if (gap == 0) {
				if (str1[i] == 'T') dpt[i][j] = 1, dpf[i][j] = 0;
				else dpt[i][j] = 0, dpf[i][j] = 1;
			}
			else {
				for (int k = i; k < j; k++) {
					char oper = str2[k];
					int lt = dpt[i][k], rt = dpt[k + 1][j];
					int lf = dpf[i][k], rf = dpf[k + 1][j];

					if (oper == '|') {
						dpt[i][j] += lt * rt + lf * rt + lt * rf;
						dpf[i][j] += lf * rf;
					}
					else if (oper == '&') {
						dpt[i][j] += lt * rt;
						dpf[i][j] += lf * rf + lf * rt + lt * rf;
					}
					else {
						dpt[i][j] += lf * rt + lt * rf;
						dpf[i][j] += lf * rf + lt * rt;
					}
				}
			}
		}
	}

	return dpt[0][n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string str1; cin >> str1;
	string str2; cin >> str2;
	cout << Evaluate(str1, str2);

	return 0;
}