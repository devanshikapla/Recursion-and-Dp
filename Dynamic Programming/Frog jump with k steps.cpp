Recursive
class Solution {
  public:
    int solve(vector<int>& height, int index, int k){
        if(index == 0) return 0;
        int mini = INT_MAX;
        for(int i = 1; i <= k ; i++){
            if(index - i >= 0){
                int curr = abs(height[index]-height[index-i])+solve(height, index-i , k);
                mini = min(mini ,curr);
            }
        }
        return mini;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        return solve(height , n - 1 , k);
    }
};

Memoized 
class Solution {
  public:
    int solve(vector<int>& height, int index, int k , vector < int >& dp){
        if(index == 0) return 0;
        int mini = INT_MAX;
        if(dp[index] != -1) return dp[index];
        for(int i = 1; i <= k ; i++){
            if(index - i >= 0){
                int curr = abs(height[index]-height[index-i])+solve(height, index-i , k , dp);
                mini = min(mini ,curr);
            }
        }
        return dp[index] = mini;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector < int > dp(n + 1 , -1);
        return solve(height , n - 1 , k , dp);
    }
};

Tabulation
int minimizeCost(vector<int>& height, int n, int k) {
        
       vector<int>dp(n , 0);
       dp[0]=0;
       for(int i=1;i<n;i++)
       {
           int minsteps=INT_MAX;
           for(int j=1;j<=k;j++)
           {
               if(i-j>=0)
               {
                   int cur=abs(height[i]-height[i-j])+dp[i-j];
                   
                   minsteps=min(minsteps,cur);
                  
               }
           }
           dp[i]=minsteps;
       }
       return dp[n-1];
}

Space optimization is possible and space can be optimized from O(n) to O(k) states as there are k previous indexes required
