int solve (vector < int > & arr , int n , int index , int buy ,  int cap , vector<vector<vector<int>>>& dp){
    if(index == n || cap == 0) return 0;
    if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
    int profit;
    if(buy == 0) profit = max(solve(arr , n , index + 1 , 0 , cap , dp) , -arr[index] + solve(arr , n , index + 1 , 1 , cap , dp));
    if(buy==1){// We can sell the stock
        profit = max(0+solve(arr,n,index + 1,1,cap,dp),
                    arr[index] + solve(arr,n,index + 1,0,cap-1,dp));
    }
    
    return dp[index][buy][cap] = profit;
}
int maxProfit(vector<int>&Arr){
    //Write your code here..
    int n = Arr.size();
    vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,0)));
                                            
    // As dp array is intialized to 0, we have already covered the base case
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], 
                                -Arr[ind] + dp[ind+1][1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],
                                Arr[ind] + dp[ind+1][0][cap-1]);
                }
            }
        }
    }
    
    
    return dp[0][0][2];
}
