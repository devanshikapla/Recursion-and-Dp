Recursion :- 
class Solution {
public:
    int solve(int num , int sum ){
        if(num == 1) return num;
        int notPick = solve(num - 1 , sum );
        int pick = 0;
        if(sum - num  >= 0)pick =  num * solve(num , sum - num );
        return max(pick , notPick); 
    }
    int integerBreak(int n) {
        return solve(n - 1 , n);
    }
};
Memoization  :- 
class Solution {
public:
    int solve(int num , int sum  , vector < vector < int >> & dp){
        if(num == 1) return num;
        if(dp[num][sum] != -1) return dp[num][sum];
        int notPick = solve(num - 1 , sum , dp);
        int pick = 0;
        
        if(sum - num  >= 0)pick =  num * solve(num , sum - num , dp);
        return dp[num][sum] = max(pick , notPick); 
    }
    int integerBreak(int n) {
        vector < vector < int >> dp ( n , vector < int > (n + 1, - 1));
        return solve(n - 1 , n , dp);
    }
};
