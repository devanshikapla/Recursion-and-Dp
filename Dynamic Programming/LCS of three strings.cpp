int solve(string a , string b , string c , int n1 , int n2, int n3 , vector < vector < vector < int>>> & dp , int i , int j , int k){
    if(i == n1) return 0;
    if(j == n2) return 0;
    if(k == n3) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(a[i] == b[j] && b[j] == c[k]){
        return dp[i][j][k] = 1 + solve(a,b,c,n1,n2,n3, dp, i + 1 , j + 1 , k + 1 );
    }
    else{
        int s1 = solve(a , b , c , n1 , n2 , n3 , dp, i + 1 , j , k );
        int s2 = solve(a, b , c , n1 , n2 , n3 , dp, i , j + 1 , k );
        int s3 = solve(a,b,c,n1,n2,n3, dp , i,j,k+1);
        return dp[i][j][k] = max(s1 , max(s2 , s3));
    }
    
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector < vector < vector < int >>> dp( n1 + 1 , vector < vector < int>> (n2 + 1 , vector < int > (n3 + 1 , -1)));
    return solve(A , B , C , n1 , n2 , n3, dp , 0 ,  0 , 0 );
    
}
