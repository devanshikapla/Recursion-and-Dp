#include <bits/stdc++.h>
int solve(int i, int j, vector<int> & a , vector < vector < int >> & dp) 
{
	if(i > j) return 0;
	int maxi  = INT_MIN;
	if(dp[i][j] != -1) return dp[i][j];
	for(int index = i ; index <= j ; index++){
		int cost = a[i - 1] * a[index] * a[j + 1] +
                   solve(i, index - 1, a , dp) + solve(index + 1, j, a , dp);
		maxi = max(maxi , cost);
	}
	return dp[i][j]= maxi;
}
int maxCoins(vector<int>& a)
{
	// Write your code here.
	int n = a.size();
	a.push_back(1);
	a.insert(a.begin() , 1);
	vector < vector < int >> dp (n + 1, vector < int> (n + 1 , -1));
	return solve(1 , n , a , dp);
}

int maxCoins(vector<int>& a)
{
	// Write your code here.
	int n = a.size();
    a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i > j) continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++) {
                int cost = a[i - 1] * a[ind] * a[j + 1] +
                           dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}
