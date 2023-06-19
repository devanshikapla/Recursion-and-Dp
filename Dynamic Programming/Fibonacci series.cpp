class Solution {

  public:
    long long int mod = 1e9 + 7;
    long long int solve(int n , vector < long long int > & dp){
        // code here
        if(n == 0) dp[0] = 0;
        if(n == 1) dp[1] = 1;
        if(dp[n] != -1) return dp[n];
        return (dp[n] = solve(n - 1 , dp) + solve(n - 2 , dp)) % mod;
    }
    long long int topDown(int n) {
        vector<long long int> dp(n+1,-1);
        return solve(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
        vector < long long int > dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n ; i++){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        return dp[n]%mod;
    }
