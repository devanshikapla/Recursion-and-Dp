Recursive : - 
#include <bits/stdc++.h>
int solve(int index , vector < int > & heights ){
    if(index == 0) return 0;
    int right = INT_MAX;
    int left = solve(index - 1 , heights) + abs(heights[index] - heights[index - 1]);
    if(index > 1) right = solve(index - 2 , heights) + abs(heights[index] - heights[index - 2]);
    return min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return solve(n - 1 , heights);
}

Memoized :- 
#include <bits/stdc++.h>
int solve(int index , vector < int > & heights  , vector < int > & dp){
    if(index == 0) return 0;
    int right = INT_MAX;
    if(dp[index] != -1) return dp[index];
    int left = solve(index - 1 , heights , dp) + abs(heights[index] - heights[index - 1]);
    if(index > 1) right = solve(index - 2 , heights , dp) + abs(heights[index] - heights[index - 2]);
    return dp[index] = min(left , right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector < int > dp(n  , -1);
    return solve(n - 1 , heights , dp);
}

Tabulation :- 
  int frogJump(int n, vector<int> &height)
{
    // Write your code here.
    vector < int > dp(n  , 0);
    dp[0] = 0;
    for(int i = 1 ; i < n ; i++){
        int right = INT_MAX;
        int left =  dp[i - 1] + abs(height[i] - height[i - 1]);
        if(i > 1) right = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(left , right);
    }
    return dp[n - 1];
}
Space Optimized : -

int frogJump(int n, vector<int> &height)
{
    // Write your code here.
    
    int prev = 0;
    int prev2 = 0;
    for(int i = 1 ; i < n ; i++){
        int right = INT_MAX;
        int left =  prev + abs(height[i] - height[i - 1]);
        if(i > 1) right = prev2 + abs(height[i] - height[i - 2]);
        int cur = min(left , right);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}
