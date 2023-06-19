//Memoization
int solve(int index , vector < int > & height , vector < int > & dp){
        if(index == 0) return 0;
        int left = solve(index - 1 , height , dp) + abs(height[index] - height[index - 1]);
        int right = INT_MAX;
        if(index > 1) right = solve(index - 2 , height , dp) + abs(height[index] - height[index - 2]);
        return dp[index] = min(left , right);
    }
  int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector < int > dp(n + 1 , -1);
        return solve(n - 1 , height , dp);
}

//Tabulation

int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector < int > dp(n , 0);
        dp[0] = 0;
        for(int i = 1; i < n ; i++){
            int first = dp[i - 1] + abs(height[i] - height[i - 1]);
            int second = INT_MAX;
            if(i > 1) second = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(first , second);
        }
        return dp[n - 1];
        
       
    }
//Space optimization
int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        int prev = 0;
        int prev2 = 0;
        for(int i = 1; i < n ; i++){
            int first = prev + abs(height[i] - height[i - 1]);
            int second = INT_MAX;
            if(i > 1) second = prev2 + abs(height[i] - height[i - 2]);
            int curi = min(first , second);
            prev2 = prev;
            prev = curi;
        }
        return prev;
        
       
    }
