class Solution {
public:
int solve(vector<vector<int>>cost , vector < vector < int >> & dp , int n , int mask , int pos){
    if(mask == (1 << n) - 1){
        return cost[pos][0];
        
    }
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        if((mask & (1 << i)) == 0) {
            int tempAns = cost[pos][i] + solve( cost , dp , n , mask | (1 << i) , i);
            ans = min(ans , tempAns);
        }
    }
    return dp[mask][pos] = ans;
}

int total_cost(vector<vector<int>>cost){
    // Code here
    int n = cost.size();
    vector < vector < int >> dp((1 << n) + 1 , vector < int > ( n + 1 , -1) );
    return solve(cost , dp , n , 1 , 0);
}
};
