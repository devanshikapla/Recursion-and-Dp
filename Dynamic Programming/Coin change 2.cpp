class Solution {
public:
    int solve(int index , int target , vector < int > & coins , vector < vector < int >> & dp){
        if(index == 0){
            if(target % coins[index] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][target] != -1) return dp[index][target];
        int notTake = solve(index - 1 , target , coins , dp);
        int take = 0;
        if(coins[index] <= target) take = solve(index , target - coins[index] , coins , dp);
        return dp[index][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector < vector < int >> dp( n , vector < int > (amount + 1 , 0));
        for(int i = 0 ; i <= amount ; i++){
            dp[0][i] = (i % coins[0] == 0);
        }
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <= amount ; j++){
                int notTake = dp[i - 1][j];
                int Take = 0;
                if(coins[i] <= j) Take = dp[i][j - coins[i]];
                dp[i][j] = Take + notTake;
            }

        }
        return dp[n - 1][amount];
    }
};
