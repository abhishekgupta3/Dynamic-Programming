// Burst Balloons
#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& nums, int n) {
    int dp[n][n];
    
    for(int gap = 0; gap < n; gap++) {
        for(int i = 0, j = gap; j < n; i++, j++) {
            int mx = INT_MIN;
            // max coins by bursting kth balloon at last
            for(int k = i; k <= j; k++) {
                int left = (k == i) ? 0 : dp[i][k - 1];
                int right = (k == j) ? 0 : dp[k + 1][j];
                int val = ((i == 0) ? 1 : nums[i - 1]) * nums[k] * ((j == n - 1) ? 1 : nums[j + 1]);
                mx = max(mx, val + left + right);
            }
            dp[i][j] = mx;
        }
    }

    return dp[0][n - 1];        
}

int main(){
    int n; cin >> n;
    vector<int> nums(n); 
    for(int i = 0; i < n; ++i) cin >> nums[i];
    
    cout << maxCoins(nums, n);

    return 0;
}