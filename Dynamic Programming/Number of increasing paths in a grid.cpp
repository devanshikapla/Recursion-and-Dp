class Solution {
public:
    int mod = 1000000007;
    int delrow[4] = {1, 0 , -1 , 0};
    int delcol[4] = {0 , 1 , 0 , -1};
    bool isValid(int x , int y , vector<vector<int>>& grid ){
        if(x < 0 || x >= grid.size() || y < 0 or y >= grid[0].size()) return false;
        return true;
    }
    int dfs(int x, int y, vector <vector<int>>&grid,vector< vector<int>> &dp){
        //just memoizing the solution;
        if(dp[x][y] != -1)return dp[x][y];
        int ans = 1;
        for(int i = 0 ; i < 4 ; i++){
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];
            if(isValid(nrow , ncol , grid) and grid[x][y] < grid[nrow][ncol]){
                ans = (ans % mod + dfs(nrow , ncol , grid , dp) % mod) % mod;
            }
        }
        return dp[x][y] = ans % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //Dp array to store previous states 
        vector < vector < int >> dp(n  , vector < int > (m , -1));
        long long cnt = 0;
        //Traversing in the grid and calling the dfs function

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                //return the ans to mod as it could be very large
                cnt = (cnt % mod + dfs(i , j , grid , dp) % mod)% mod;
            }
        }
        //type casting from long to int
        return (int)cnt % mod;
    }
};
