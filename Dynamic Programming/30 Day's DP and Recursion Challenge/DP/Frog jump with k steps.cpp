Recursive :-
  int solve(int index , int k , vector < int > & height){
    if(index == 0) return 0;
    int minSteps = INT_MAX;
    for(int j = 1 ; j <= k ; j++){
        if(index - j >= 0){
            int jump = solve(index - j , k , height) + abs(height[index]- height[index - j]);
            minSteps = min(minSteps , jump);
        }

    }
    return minSteps;
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    return solve(n - 1 , k, height );
}

Memoized  :- 
int solve(int index , int k , vector < int > & height , vector < int > & dp){
    if(index == 0) return 0;
    int minSteps = INT_MAX;
    if(dp[index]!= -1) return dp[index];
    for(int j = 1 ; j <= k ; j++){
        if(index - j >= 0){
            int jump = solve(index - j , k , height , dp) + abs(height[index]- height[index - j]);
            minSteps = min(minSteps , jump);
        }

    }
    return dp[index] = minSteps;
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector < int > dp(n + 1 , -1);
    return solve(n - 1 , k, height  , dp);
}

Tabulation :- 

int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector < int > dp(n + 1 , 0);
    dp[0] = 0;

    for(int i = 1 ; i < n ; i++){
        int mini = INT_MAX;
        for(int j = 1; j <= k ; j++){
            if(i - j >= 0){
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mini = min(mini , jump);
            }
        }
        dp[i] = mini;
    }
    return dp[n - 1];
}
