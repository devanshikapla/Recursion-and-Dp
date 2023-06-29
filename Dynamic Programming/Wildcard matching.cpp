int f(int i, int j ,string s1, string s2, vector<vector<int>>&dp){
        if(i<0 && j<0) return 1;
        if(i<0 && j>=0) return 0;
        if(i>=0 && j<0){
            for(int p=0; p<=i; p++){
                if(s1[p]!='*') return 0;
            }return 1;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j] || s1[i]=='?'){
            return dp[i][j]=f(i-1, j-1, s1, s2, dp);
        }
        if(s1[i]=='*'){
            return dp[i][j]=(f(i-1, j, s1, s2, dp) || f(i, j-1, s1, s2, dp));
        }
    }

    int wildCard(string pattern,string str)
    {
        int x=pattern.size();
        int y=str.size();
        vector<vector<int>>dp(x, vector<int>(y, -1));
        return f(x-1, y-1, pattern, str, dp);
    }

 int wildCard(string pattern,string str)
    {
        int n = pattern.length();
        int m = str.length();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        dp[0][0] = 1;
        for(int i=1;i<=m;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            if(pattern[i-1] != '*')
            {
                break;
            }
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(pattern[i-1] == str[j-1] or pattern[i-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[i-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};
