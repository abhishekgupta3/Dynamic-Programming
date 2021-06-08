// Mobile Numeric Keypad ( All Letter combination)
//     1 2 3
//     4 5 6
//     7 8 9
//     * 0 #
//************************************************************************
#include <bits/stdc++.h>
using namespace std;

long long getCount(int n) {

    vector<int> nbrs[10]; // all possible neighbours

    nbrs[0] = {0, 8};
    nbrs[1] = {1, 2, 4};
    nbrs[2] = {1, 2, 3, 5};
    nbrs[3] = {2, 3, 6};
    nbrs[4] = {1, 4, 5, 7};
    nbrs[5] = {2, 4, 5, 6, 8};
    nbrs[6] = {3, 5, 6, 9};
    nbrs[7] = {4, 7, 8};
    nbrs[8] = {5, 7, 8, 9, 0};
    nbrs[9] = {6, 8, 9};

    long long dp[n][10];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < 10; i++)dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            // traversing all directions possible
            for (auto k : nbrs[j]) {
                // dp[i][j] represnts all combinations possible
                // when the number ends with j
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    // last row stores all possible combination with number of length n
    long long sum = 0;
    for (int j = 0; j < 10; j++) sum += dp[n - 1][j];

    return sum;
}

int main() {

    int n; cin >> n;
    cout << getCount(n);

    return 0;
}
