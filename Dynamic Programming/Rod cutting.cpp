int solve(int index , int n , vector<int> &price  , vector < vector < int >> & dp){
	if(index == 0) return n * price[0];
	if(dp[index][n] != -1) return dp[index][n];
	int notTake = solve(index - 1 , n , price , dp);
	int take = INT_MIN;
	int rodLength = index + 1; 
	
	if(rodLength <= n) {
		take = price[index] + solve(index , n - rodLength , price , dp);
	}
	return dp[index][n] = max(take , notTake);
}
int cutRod(vector<int> &price, int N) {
  // Write your code here.
   vector<vector<int>> dp(N,vector<int>(N+1,-1));
    
    for(int i=0; i<=N; i++){
        dp[0][i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[N-1][N];
}
int cutRod(vector<int> &price, int N) {
  // Write your code here.
    vector<int> cur (N+1,0);
    
    for(int i=0; i<=N; i++){
        cur[i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + cur[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + cur[length-rodLength];
        
             cur[length] = max(notTaken,taken);   
        }
    }
    
    return cur[N];
}
