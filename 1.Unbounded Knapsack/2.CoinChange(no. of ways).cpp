// coin change (number of distinct ordered ways)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005][1005];


// coin change recursive T.C: O(2^n)
int coinChangeRec(int ar[] , int n, int sum) {
	if (sum == 0 ) return 1;
	if (n == 0 ) return 0;
	if (ar[n - 1] > sum) {
		return coinChangeRec(ar, n - 1, sum);
	}
	return  coinChangeRec(ar, n , sum - ar[n - 1]) +  coinChangeRec( ar, n - 1, sum);
}

// coin change memoization T.C: O(n*sum) A.S: O(n*sum)
int coinChangeMemo(int ar[] , int n, int sum, int dp[][1005]) {
	if (sum == 0 ) return 1;
	if (n == 0 ) return 0;
	if (dp[sum][n] != -1) return dp[sum][n];

	if (ar[n - 1] > sum) {
		dp[sum][n] = coinChangeRec(ar, n - 1, sum);
	}

	else dp[sum][n] = coinChangeMemo(ar, n , sum - ar[n - 1], dp) +  coinChangeMemo( ar, n - 1, sum, dp);
	return dp[sum][n];
}

// coin change optimized T.C: O(n*sum) A.S: O(sum)
int coinChangeOptimized(int ar[],int n,int sum){
	vector<int> dp(sum+1,0);
	dp[0]=1;
		
	for(int i=0;i<n;i++){
       		 for(int j=0;j<=sum;j++){
		     	if(j>=ar[i]){
		         	dp[j]+=dp[j-ar[i]];
		     	}
		 }
	}

	return dp[sum];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, sum;
	cin >> n >> sum;
	int ar[n];

	for (int i = 0; i < n; ++i)	{
		cin >> ar[i];
	}

	cout << coinChangeRec(ar, n, sum) << endl;
	int dp[sum + 1][1005];
	memset(dp, -1, sizeof dp);
	cout << coinChangeMemo(ar, n, sum, dp) << endl;

	// coin change dp solution( bottom up) T.C : O(n*sum)  A.S : O(n*sum)
	for (int i = 0; i <= sum; i++) dp[i][0] = 0;
	for (int i = 0; i <= n; i++) dp[0][i] = 1;

	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= n; j++) {
			if (ar[j - 1] > i) {
				dp[i][j] = dp[i][j - 1];
			}
			else {
				dp[i][j] =  dp[i - ar[j - 1]][j] + dp[i][j - 1];
			}
		}
	}


	for (int i = 0; i <= sum; i++) {
		for (int j = 0; j <= n; j++) {
			cout << dp[i][j] << " ";
		} cout << endl;
	}
	cout << dp[sum][n] << endl;


	return 0;

}