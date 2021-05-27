// Best Time to buy and sell a stock: One Transaction
// Approach: we maintain min so far and calculate profit for each day
//////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

// T.C: O(N)
int profit(vector<int> arr) {
	int ans = 0, min_so_far = arr[0];
	for (int i = 1; i < arr.size() ; ++i) {
		if (arr[i] - min_so_far > ans)ans = arr[i] - min_so_far;
		min_so_far = min(min_so_far, arr[i]);
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