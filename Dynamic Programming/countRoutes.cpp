class Solution {
public:
    int mod = 1e9 + 7;
    int solve(vector < int > & locations , int start , int finish , int fuel , vector < vector < int >> & dp){
        if(fuel < 0) return 0;
        int ans = 0;

        if(dp[start][fuel] != -1) return dp[start][fuel];
        if(start == finish) ans++;
        for(int i = 0 ; i < locations.size() ; i++){
            if(i == start || abs(locations[i] - locations[start] ) > fuel) continue;
            ans += solve(locations , i , finish , fuel - abs(locations[i] - locations[start] ) , dp);
            ans %= mod;
        }
        return dp[start][fuel]  = ans % mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int size = locations.size();
        vector < vector < int >> dp(size , vector < int > (fuel + 1 , -1));
        return solve(locations , start , finish , fuel , dp);

    }
};
