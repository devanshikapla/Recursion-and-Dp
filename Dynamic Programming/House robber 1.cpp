//Recursion
int solve(int index, int *arr ){
	    if(index == 0) return arr[index];
	    if(index < 0) return 0;
	    int pick = arr[index] + solve(index - 2 , arr);
	    int nonPick = solve(index - 1 , arr );
	    return  max(pick , nonPick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    return solve(n - 1 , arr);
	}

//Memoization
int solve(int index, int *arr ,vector < int > & dp){
	    if(index == 0) return arr[index];
	    if(index < 0) return 0;
	    if(dp[index]!= -1) return dp[index];
	    int pick = arr[index] + solve(index - 2 , arr , dp);
	    int nonPick = solve(index - 1 , arr , dp );
	    return  dp[index] = max(pick , nonPick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector < int > dp(n + 1 , -1);
	    return solve(n - 1 , arr , dp);
	}
//Tabulation
#include <bits/stdc++.h> 
int solve(int index , vector < int > & arr, 
   vector < int > & dp){
       dp[0] = arr[0];
       for(int i = 1; i < index ; i++){
           int pick = arr[i];
           if(i > 1) pick += dp[i - 2];
           int nonPick = dp[i - 1];
           dp[i] = max(pick , nonPick);
       }
       return dp[index - 1];
   }
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector < int > dp(n , -1);
    return solve(n , nums , dp);
    
}
//Space optimization
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = nums[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = nums[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
