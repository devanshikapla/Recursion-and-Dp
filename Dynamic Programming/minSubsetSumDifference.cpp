#include <bits/stdc++.h>
bool subsetSumUtil(int ind, int target, vector < int > & arr, vector < vector 
< int >> & dp) {
  if (target == 0)
    return dp[ind][target]=true;

  if (ind == 0)
    return dp[ind][target] = arr[0] == target;

  if (dp[ind][target] != -1)
    return dp[ind][target];

  bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

  bool taken = false;
  if (arr[ind] <= target)
    taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken || taken;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totalSum = 0;
	for(auto it : arr){
		totalSum = totalSum + it;
	}
	vector < vector < int >> dp(n, vector < int > (totalSum + 1, -1));
    for(int i = 0 ; i <= totalSum ; i++){
		bool total = subsetSumUtil(n - 1 , i , arr, dp);
	}
	int mini = 1e9;
	for(int i = 0 ; i <= totalSum ; i++){
		if(dp[n - 1][i] == true){
			int diff = abs(i - (totalSum - i));
			mini = min(mini , diff);
		}
	}
	return mini;
}
