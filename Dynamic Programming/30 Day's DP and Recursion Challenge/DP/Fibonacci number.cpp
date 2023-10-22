Recursive :- 
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
       
    }
};
Memoization:-
class Solution {
public:
    int solve(int n , vector < int > & dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = solve(n - 1 , dp) + solve(n - 2 , dp);
        return dp[n];
    }
    int fib(int n) {
        vector < int > dp(n + 1 , -1);
        return solve(n , dp);
       
    }
};

Tabulation :-

class Solution {
public:
    
    int fib(int n) {
        vector < int > dp(n + 2 , 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2 ; i < n + 1 ; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
            
        }
        return dp[n];
       
    }
};

Space Optimization :- 

class Solution {
public:
    int fib(int n) {
       int prev1=0;
       if(n==0) return prev1;
       int prev=1;
       for(int i=2; i <= n; i++){
           int curr = prev + prev1;
           
           prev1=prev;
           prev=curr;
       }
       return prev;
       
    }
};
