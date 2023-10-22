Recursion :-
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int left = climbStairs(n - 1);
        int right = climbStairs(n - 2);
        return left + right;
    }
};
Memoization 
class Solution {
public:
    int solve(int n, vector < int > & dp){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1 , dp) + solve(n - 2 , dp);
    }
    int climbStairs(int n) {
        vector < int > dp(n + 1 , -1);
        return solve(n , dp);
    }
};

Tabulation :- 
class Solution {
public:
    
    int climbStairs(int n) {
        vector < int > dp(n + 1 , 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[ i - 1] + dp[i - 2];

        }
        return dp[n];
    }
};

Space optimization :-
class Solution {
public:
    
int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;
  
        for(int i=2; i<=n; i++){
            int cur_i = prev2+ prev;
            prev2 = prev;
            prev= cur_i;
        }
        return prev;
    }
};
