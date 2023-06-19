class Solution
{
    public:
    int mod = 1000000007;
    int solve(int n , vector < int > & dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n]%mod;
        return dp[n]=solve(n-1, dp)%mod+solve(n-2, dp)%mod;
    }
    int countWays(int n)
    {
        vector < int > dp(n + 1 , -1);
        
        int ans = solve(n , dp);
        return ans % mod;
    }
};
