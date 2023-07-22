#include<bits/stdc++.h>
class Solution
{
    public:
        long long lucas(int n)
        {
            //code here.
            int mod = 1e9 + 7;
            vector < long long > dp(n + 1 , -1);
            dp[0] = 2;
            dp[1] = 1;
            for(int i = 2; i <= n ; i++){
                dp[i] = (dp[ i - 1 ] + dp[i - 2]) % mod;
            }
            return dp[n] ;
        }
        
};
