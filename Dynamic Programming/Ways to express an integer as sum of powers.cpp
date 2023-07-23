class Solution {
public:
/*
    n = i1 ^ x + i2^x +..................i300 ^ x 
    I have two options to take or not take 

    4 = 1 ^ 1 + 2 ^ 1 + 3 ^ 1 + 4 ^ 1 

    I have two options to take or not take , for example if i chose 1 then i have to obtain remaining of 4 - 1 sum
    Same stuff can be done for every number starting from 1
    i will take i and remaining will be n  - i^x 

*/
    long long dp[305][305];
    long long mod = 1e9 + 7;
    long long solve(long long n , long long x , long long i ){
        if(n == 0) return 1;
        //if(n < 0) return 0;
        if(pow(i , x) > n ) return 0;
        //if(n < 0 || pow(i , x) > n) return 0;
        if(dp[n][i] != -1) return dp[n][i];
        long long take = solve(n - pow(i , x) , x , i + 1);
        long long notTake = solve(n , x  , i + 1);

        long long sum = (take + notTake) % mod; 

        return dp[n][i] = sum;

    }

    int numberOfWays(int n, int x) {
        memset(dp , -1 , sizeof(dp));
        return (int)solve(n , x , 1);
    }
};
