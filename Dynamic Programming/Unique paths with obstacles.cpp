Memoized and tabulated solution

class Solution {
  public:
   #define mod 1000000007
  
    int solve(int n , int m , vector<vector<int>>& grid , vector<vector<int>>&dp){
        if(n >= 0 && m >= 0 && grid[n][m] == 1) return 0;
        if(n < 0 || m < 0) return 0;
        if(n == 0 && m == 0) return 1;
        int up = solve(n - 1 , m  , grid , dp) % mod;
        int left = solve(n , m - 1 , grid , dp) % mod;
        return dp[n][m] = (up + left) % mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0, up = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    
                    dp[i][j] = (left + up) % mod;
                }
            }
        }
        return dp[n-1][m-1];
    
    }
};
