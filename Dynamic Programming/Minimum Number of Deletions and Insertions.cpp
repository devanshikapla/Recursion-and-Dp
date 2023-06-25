#include <bits/stdc++.h> 
int lcs(string & str , string & ptr , int n , int m , vector < vector < int >> & dp)
{
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0;
    }
    for(int j = 0 ; j <= m ; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m ; j++){
            if(str[i - 1] == ptr[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();
    vector < vector < int >> dp(n + 1 , vector < int > (m + 1 , -1));
    int ans = lcs(str , ptr , n , m ,dp );
    return n + m - 2*ans;
}
