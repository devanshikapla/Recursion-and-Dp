Recursive
int solve(int i , int j ){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        int up = solve(i - 1 , j);
        int left = solve(i , j - 1);
        return up + left;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        return solve(a-1, b-1);
    }
//Memoized
//Function to find total number of unique paths.
    int solve(int i , int j , vector < vector < int >> & dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i - 1 , j , dp);
        int left = solve(i , j - 1 , dp);
        return dp[i][j] = up + left;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        vector < vector < int >> dp( a + 1 , vector < int > (b + 1 , -1));
        return solve(a-1, b-1 , dp);
    }

//Tabulation
int NumberOfPath(int a, int b)
    {
        //code here
        vector < vector < int >> dp( a  , vector < int > (b  , 1));
        dp[0][0] = 1;
        for(int i = 1; i < a ; i++){
            for(int j = 1; j < b ; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[a - 1][b - 1];
    }

//Space optimization
int NumberOfPath(int a, int b)
    {
        //code here
        
        int dp[a][b];
        vector<int>prev(b, 0);
        for(int i=0; i<a; i++){
            vector<int>curi(b, 0);
            for(int j=0; j<b; j++){
                if(i==0 && j==0) curi[j]=1;
                else{
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=curi[j-1];
                curi[j]=up+left;
                }
            }
            prev=curi;
        }
        return prev[b-1];
    }
