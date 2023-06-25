#include <bits/stdc++.h>
int prime = 1e9+7;

int countUtil(string s1, string s2, int ind1, int ind2,vector<vector<int>>& dp){
    if(ind2<0)
        return 1;
    if(ind1<0)
        return 0;
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1]==s2[ind2]){
        int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
        int stay = countUtil(s1,s2,ind1-1,ind2,dp);
        
        return dp[ind1][ind2] = (leaveOne + stay)%prime;
    }
    
    else{
        return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
    }
}

int subsequenceCounting(string &t, string &s, int n, int m) {
    // Write your code here.
    
    //vector<vector<int>> dp(lt,vector<int>(ls,-1));
    //return countUtil(t,s,lt-1,ls-1,dp);
    vector < vector < int >> dp(n + 1 , vector < int > ( m + 1 , -1));
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 1;

    }
    for(int j = 1; j <= m ; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m ; j++){
            if(t[i - 1] == s[j - 1]){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % prime;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
} 
