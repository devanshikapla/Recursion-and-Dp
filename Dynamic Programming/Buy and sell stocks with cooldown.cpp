#include <bits/stdc++.h> 
int solve(vector < int > & prices , int index , int buy , int n , vector < vector < int >> & dp){
    if(index >= n) return 0;
    if(dp[index][buy] != -1) return dp[index][buy];

    int profit ;
    if(buy == 0){
        profit = max(solve(prices , index + 1 , 0 , n , dp), -prices[index] + solve(prices , index + 1 , 1 , n , dp));

    }
    if(buy == 1){
        profit = max(0+solve(prices,index+1,1,n,dp), prices[index]+solve(prices,index +2,0,n,dp));
    }
    return dp[index][buy] = profit;
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    vector<vector<int>> dp( n + 2,vector<int>(2, 0 ));
    //int ans = solve(prices , 0 , 0 , n , dp);
    //return ans;
    for(int index = n - 1; index >= 0 ; index--){
        for(int buy = 0 ; buy <= 1; buy++){
            int profit;
            if(buy == 0) profit = max(dp[index + 1][0] , -prices[index] + dp[index+1][1]);
            if(buy == 1) profit = max(dp[index+1][1] , prices[index] + dp[index+2][0]);
            dp[index][buy] = profit;
        }
    }
    return dp[0][0];

}
