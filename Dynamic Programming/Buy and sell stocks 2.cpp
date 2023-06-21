Memoization
class Solution{
    public:
    long long maximum(vector<long long> & prices, int n, int sold, vector<vector<long long>> & v){
        if(n<0){
            if(sold == 1){
                return -1000000;
            }
            return 0;
        }
        if(v[n][sold] != -1){
            return v[n][sold];
        }
        if(sold == 0){
            return v[n][sold] = max(maximum(prices,n-1,1,v) + prices[n],maximum(prices,n-1,0,v));
        }
        return v[n][sold] =  max(maximum(prices,n-1,0,v) - prices[n],maximum(prices,n-1,1,v));
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        vector<vector<long long>> v(100000,vector<long long>(2,-1));
        return maximum(prices,n-1,0,v);
    }
};

//tabulation

long long maximumProfit(vector<long long>&prices, int n) {
       vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                   
                if(buy){
                     dp[ind][buy]= max(-prices[ind]+dp[ind+1][0],
                     dp[ind+1][buy]);
                }
                else{
                 dp[ind][buy]= max(prices[ind]+dp[ind+1][1],dp[ind+1][buy]);
                }
            }
        }
        return dp[0][1];
    }
