// Best Time to Buy and Sell Stock with Cooldown

#include <bits/stdc++.h>
using namespace std;

// op1 -> buy stock
// op2 -> sell stock
// op3 -> skip

int Profit(vector<int>& prices, int i, int state, vector<vector<int>>&dp) {
	if (i >= prices.size())return 0;

	if (dp[i][state] != -1)return dp[i][state];
	if (state == 1) {
		int op1 = -prices[i] + Profit(prices, i + 1, 2, dp); // buy
		int op3 = Profit(prices, i + 1, 1, dp); // skip
		return dp[i][state] = max(op1, op3);
	}
	else {
		int op2 = prices[i] + Profit(prices, i + 2, 1, dp); // sell
		int op3 = Profit(prices, i + 1, 2, dp); // skip
		return dp[i][state] = max(op2, op3);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vector<int> prices(n);
	for (int i = 0; i < n; ++i)	{
		cin >> prices[i];
	}

	vector<vector<int>>dp(prices.size() + 1, vector<int>(3, -1));
	return Profit(prices, 0, 1, dp);

	return 0;
}