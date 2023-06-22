#include <bits/stdc++.h> 
bool solve(int index , int target , vector < int > & arr , 
vector<vector<int>> &dp){
    if(target == 0) return true;
    if(index == 0) return arr[0] == target;
    if(dp[index][target] != -1){
        return dp[index][target];

    }
    bool notTaken = solve(index - 1 , target , arr , dp);
    bool taken = false;
    if(arr[index] <= target){
        taken = solve(index - 1 , target - arr[index] , arr , dp);

    }
    return dp[index][target] = taken || notTaken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k + 1, 0));
    for(int i = 0 ; i < n  ; i++){
        dp[i][0] = true;
    }
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int index = 1; index < n ; index++){
        for(int target = 1 ; target <= k ; target ++){
            bool notTaken = dp[index - 1][target] ;
            bool taken = false;
            if(arr[index] <= target){
                taken = dp[index - 1][target - arr[index]];

            }
             dp[index][target] = taken || notTaken;
        }
    }
    return dp[n - 1][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector < bool > prev ( k  + 1 , 0) ,curr (k + 1 , 0);
    prev[0] = true;
    curr[0] = true;
    prev[arr[0]] = true;
    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(k+1,false);
        cur[0] = true;
        for(int target= 1; target<=k; target++){
            bool notTaken = prev[target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            cur[target]= notTaken||taken;
        }
        prev = cur;
    }
    
    return prev[k];

}
