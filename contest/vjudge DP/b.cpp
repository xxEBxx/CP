#include <bits/stdc++.h>
using namespace std;

// Recursive function to count the numeber of distinct ways
// to make the sum by using n coins

int count(vector<int>& coins, int n, int sum,
		vector<vector<int> >& dp)
{
	if (sum == 0)
		return dp[n][sum] = 1;

	if (n == 0 || sum < 0)
		return 0;
		
	if (dp[n][sum] != -1)
		return dp[n][sum];

	return dp[n][sum]
		= count(coins, n, sum - coins[n - 1], dp)
			+ count(coins, n - 1, sum, dp);
}

int main() {
    int t,n,value;
    vector<int> arr={1,5,10,25,50};
    while (!cin.eof()){
        cin>>value;
        vector<vector<int> > dp(n + 1,
                                vector<int>(7500, -1));
        cout<<count(arr,5,value,dp)<<endl;
    }
    return 0;
}
