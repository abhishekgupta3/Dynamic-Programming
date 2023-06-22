#include <bits/stdc++.h>
using namespace std;

int dp[50005][2];
int solve(vector<int> &nums, int i, int state, int fee)
{
    if(i == nums.size()) return 0;

    if(dp[i][state] != -1) return dp[i][state];
    int a = 0, b = 0;
    if(state == 0)
    {
        a = -nums[i] - fee + solve(nums, i + 1, 1, fee);
        b = solve(nums, i + 1, 0, fee);
    }
    else
    {
        a = nums[i] + solve(nums, i + 1, 0, fee);
        b = solve(nums, i + 1, 1, fee);
    }
    return dp[i][state] = max(a, b);
}

int main() {
	vector<int> v {10, 22, 5, 75, 65, 80};
	int fee = 2;
	memset(dp, -1, sizeof dp);
    int state = 0;
    cout << solve(prices, 0, state, fee);

	return 0;
}