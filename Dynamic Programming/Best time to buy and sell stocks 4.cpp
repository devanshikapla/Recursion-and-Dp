class Solution {
public:
    int solve(int index , int buy , int cap , vector < int > & prices , int n , vector < vector < vector < int >>> & dp){
        if(cap == 0) return 0;
        if(index == n) return 0;
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        if (buy) return dp[index][buy][cap] = max(-prices[index] + solve(index+1, 0, cap, prices, n, dp), 0 + solve(index+1, 1, cap, prices, n, dp));
        else return dp[index][buy][cap] = max(prices[index] + solve(index+1, 1, cap-1, prices, n, dp), 0 + solve(index+1, 0, cap, prices, n, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n  + 1 , vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int ind = n -1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1; buy++){
                for(int cap = 1; cap <= k ; cap++){
                    if (buy) dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                    else dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        for (int ind=n-1; ind>=0; ind--) {
            for (int buy=0; buy<=1; buy++) {
                for (int cap=1; cap<=k; cap++) {
                    if (buy) curr[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                    else curr[buy][cap] = max(prices[ind] + after[1][cap-1], 0 + after[0][cap]);
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};
