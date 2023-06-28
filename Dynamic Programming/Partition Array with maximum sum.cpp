class Solution {
public:
    int solve(int index , vector < int >  & nums , int k   , vector < int > & dp){
        int n = nums.size();
        if(index == n) return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        if(dp[index] != -1) return dp[index];
        for(int j = index ; j < min(index + k , n) ; j++){
            len++;
            maxi = max(maxi , nums[j]);
            int sum = len* maxi + solve(j + 1 , nums , k , dp);
            maxAns = max(maxAns , sum);
        }
        return dp[index] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector < int > dp( n + 1 , 0);
        for(int index = n - 1; index >= 0 ; index--){
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            for(int j = index ; j < min(index + k , n) ; j++){
                len++;
                maxi = max(maxi , arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns , sum);
            }
            dp[index] = maxAns;
        }
        return dp[0];
    }
};
class Solution {
public:
    int solve(int index , vector < int >  & nums , int k   , vector < int > & dp){
        int n = nums.size();
        if(index == n) return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        if(dp[index] != -1) return dp[index];
        for(int j = index ; j < min(index + k , n) ; j++){
            len++;
            maxi = max(maxi , nums[j]);
            int sum = len* maxi + solve(j + 1 , nums , k , dp);
            maxAns = max(maxAns , sum);
        }
        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector < int > dp( n , -1);
        return solve(0 , arr , k , dp);
    }
};
