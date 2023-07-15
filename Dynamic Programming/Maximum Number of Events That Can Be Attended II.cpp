class Solution {
public:
    int solve(vector<vector<int>>& events, int i, int k , vector < vector < int >> & dp , int n){
        if(k <= 0 || i >= n) return 0;
        int start = events[i][0];
        int end = events[i][1];
        int value = events[i][2];
        if(dp[i][k] != -1) return dp[i][k];
       // int j = i + 1;
        vector<int> temp = {end, INT_MAX, INT_MAX};
        int j = upper_bound(events.begin(), events.end(), temp) - events.begin();

        int take = value + solve(events , j , k - 1 ,dp ,  n);
        int skip = solve(events , i + 1 , k , dp, n);
        return dp[i][k] = max(take , skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1 , vector < int > (k + 1 , -1));
        return solve(events , 0 , k , dp , n );
    }
};
