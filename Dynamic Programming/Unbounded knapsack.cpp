#include <bits/stdc++.h> 

int solve(int index , int W , 
   vector < int > & val , vector < int > & weight){
   if(index == 0) return ((int) (W / weight[0])) * val[0];
   int notTake = solve(index - 1 , W , val , weight);
   int take = 0;
   if(weight[index] <= W){
       take = val[index] + solve(index , W - weight[index] , val , weight);
   }
   return max(take , notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return solve(n - 1 , w , profit , weight);
}

int solve(int index , int W , 
   vector < int > & val , vector < int > & weight , vector < vector < int >>& dp){
   if(index == 0) return ((int) (W / weight[0])) * val[0];
  
   int take = 0;
   if(dp[index][W] != -1) return dp[index][W];
   int notTake = solve(index - 1 , W , val , weight , dp);
   if(weight[index] <= W){
       take = val[index] + solve(index , W - weight[index] , val , weight , dp);
   }
   return dp[index][W] =  max(take , notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &weight)
{
    // Write Your Code Here.
    vector < vector < int >> dp(n + 1 , vector < int > (w + 1 , 0 ));
    for(int W = 0 ; W <= w ; W++){
        dp[0][w] = ((int) (W / weight[0])) * ( val[0]);

    }
    for(int index = 1; index < n ; index++){
        for(int W = 0 ; W <= w ; W++){
            int take = 0;
            //if(dp[index][W] != -1) return dp[index][W];
            int notTake = dp[index - 1][W];
            if(weight[index] <= W){
                take = val[index] + dp[index][W - weight[index]];
            }
             dp[index][W] =  max(take , notTake);
        }
    }
    return dp[n - 1][w];
    
}
