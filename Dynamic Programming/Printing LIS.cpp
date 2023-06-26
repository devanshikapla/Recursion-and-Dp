class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector < int > dp(n , 1);
        vector < int > hash(n , 1);
        int ans = -1;
        int lastIndex = 0;
        for(int i = 0 ; i < n ; i++){
            hash[i] = i;
            for(int j = 0 ; j < i ; j++){
                if(arr[i] > arr[j] && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                    if(ans < dp[i]){
                        lastIndex = i;
                        ans = dp[i];
                    }
                }
            }
        }
        vector < int > s;
        s.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            s.push_back(arr[lastIndex]);
        }
        reverse(s.begin() , s.end());
        return s;
    }
};
