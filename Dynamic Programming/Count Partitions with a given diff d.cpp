#include <bits/stdc++.h>
int solve(int index , int target ,
     vector<int>& arr, vector<vector<int>> &dp){
    if(index == 0){
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || target == arr[0]) return 1;
        return 0;
    }
    if(dp[index][target] != -1) return dp[index][target];

    int notTaken = solve(index - 1 , target , arr , dp);
    int taken = 0;
    if(arr[index] <= target){
        taken = solve(index - 1 , target - arr[index] , arr , dp);

    }
    return dp[index][target] = notTaken + taken;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int Total = 0 ;
    for(auto it : arr){
        Total = Total + it;
    }
    if(Total - d < 0) return 0;
    if((Total - d) % 2 == 1) return 0;
    int S2 = (
      Total - d
    )/2;
    vector<vector<int>> dp(n,vector<int>(S2+1,-1));
    return solve(n - 1 , S2 , arr , dp);
    
}


