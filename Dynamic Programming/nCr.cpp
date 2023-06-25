int nCr(int n, int r){
        // code here
        vector < vector <long long >> dp(n + 1 , vector < long long > (r + 1, 0));
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= r ; j++){
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<=n;i++)
        dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=r;j++)
            {
                dp[i][j]=((dp[i-1][j])%(1000000007)+dp[i-1][j-1]%(1000000007))%(1000000007);
            }
        }
        return (int)dp[n][r];
        
    }
