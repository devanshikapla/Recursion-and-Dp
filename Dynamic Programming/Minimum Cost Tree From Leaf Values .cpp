class Solution {
public:
    int solve(vector<int>& arr , map < pair < int , int > ,int> & mpp , int left , int right ,vector < vector < int >>& dp){
        if(left == right) {
            return 0;
        }
        int ans = INT_MAX;
        if(dp[left][right] != -1) return dp[left][right];
        for(int i = left; i < right ; i++){
            ans = min(ans , mpp[{left , i}] * mpp[{i + 1 , right}] + solve(arr , mpp , left , i , dp ) + solve(arr, mpp , i + 1 , right , dp));
        }
        return dp[left][right] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        //precomputing values;
        map < pair < int , int > ,int>mpp;
        int n = arr.size();
        vector < vector < int >> dp (  n + 1 , vector < int > (n + 1 , -1));
        for(int i = 0 ; i < arr.size() ; i++){
            mpp[{i , i}] = arr[i];
            for(int j = i + 1; j < arr.size() ; j++){
                mpp[{i , j}] = max(arr[j] , mpp[{i , j - 1}]);
            }
        }
        return solve(arr , mpp, 0 , arr.size() - 1  , dp);
    }
};
