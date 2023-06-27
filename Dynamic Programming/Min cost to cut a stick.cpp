#include <bits/stdc++.h>


int solve(int i , int j , vector < int > & cuts , vector < vector < int >> & dp){
    if(i > j ) return 0;
    int mini = INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    for(int index = i ; index <= j ; index++){
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i , index - 1 , cuts , dp) + solve(index + 1 , j , cuts , dp);
        mini = min(mini , cost);
    }
    return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts){
    
    cuts.push_back(n);
    cuts.insert(cuts.begin() , 0);
    vector < vector < int >> dp(c + 2 , vector < int > ( c + 2 , 0));

    sort(cuts.begin() , cuts.end());
    for(int i = c ; i >= 1 ; i--){
        for(int j = 1; j <= c ; j++){
            if(i > j) continue;
            int mini = INT_MAX;
            for(int index = i ; index <= j ; index++){
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][index-1] + dp[index+1][j];
                mini = min(mini , ans);

            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
    //return solve(1 , c , cuts , dp);
}
