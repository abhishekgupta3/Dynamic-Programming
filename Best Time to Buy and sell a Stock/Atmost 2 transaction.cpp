// Best Time to buy and sell a stock: atmost 2 Transaction
// Approach 1: General case of atmost k transaction (make a dp table of 3*(n+1) size)
// Approach 2: Make 2 DP array.
// 			   dp1[i] stores the max profit if stock is buyed before and sold on ith day or before
// 			   dp2[i] stores the max profit if stock is buyed after or on ith day and sold later
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

// T.C: O(N) A.S: O(N)
int profit(vector<int> arr) {
	int n = arr.size(), ans = 0;
	int dp1[n], dp2[n];

	// filling dp 1
	int min_so_far = arr[0], max_so_far = INT_MIN;
	for (int i = 0; i < n ; ++i) {
		max_so_far = max(max_so_far, arr[i] - min_so_far);
		dp1[i] = max_so_far;
		min_so_far = min(min_so_far, arr[i]);
	}

	// filling dp 2
	int diff = INT_MIN;
	max_so_far = INT_MIN;
	for (int i = n - 1; i >= 0; i--) {
		max_so_far = max(max_so_far, arr[i]);
		diff = max(diff, max_so_far - arr[i]);
		dp2[i] = diff;

	}

	for (int i = 0; i < n; ++i)	ans = max(ans, dp1[i] + dp2[i]);

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