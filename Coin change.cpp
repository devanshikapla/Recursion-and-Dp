//memoization 
int solve(int ind,int amount,vector<int> &coins , vector < vector < int >> & dp)
    {
        if(ind==0)
        {
            if(amount%coins[0]==0)
                return amount/coins[0];
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake=0+solve(ind-1,amount,coins , dp);
        int take=INT_MAX;
        if(coins[ind]<=amount)
            take=1+solve(ind,amount-coins[ind],coins , dp);
        return dp[ind][amount] = min(take,notTake);
        
    }
//Tabulation
int coinChange(vector<int>& arr, int T) {
       int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
    }
//Space optimization
int coinChange(vector<int>& arr, int T) {
         int n= arr.size();
    
            vector<int> prev(T+1,0), cur(T+1,0);
    
            for(int i=0; i<=T; i++){
                if(i%arr[0] == 0)prev[i] = i/arr[0];
                else prev[i] = 1e9;
            }
    
            for(int ind = 1; ind<n; ind++){
                for(int target = 0; target<=T; target++){
            
                    int notTake = 0 + prev[target];
                    int take = 1e9;
                    if(arr[ind]<=target)take = 1 + cur[target - arr[ind]];
                
                    cur[target] = min(notTake, take);
                }
                prev = cur;
            }
    
            int ans = prev[T];
            if(ans >=1e9) return -1;
            return ans;

     }
