// Best Time to buy and sell a stock: Infinite Transaction
// Approach: whenever there is a rise we take that profit
/////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

// T.C: O(N)
int profit(vector<int> arr) {
	int ans = 0;
	for (int i = 0; i < arr.size() - 1; ++i) {
		if (arr[i] < arr[i + 1])ans += arr[i + 1] - arr[i];
	}

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> v {10, 22, 5, 75, 65, 80};
	cout << profit(v);


	return 0;
}