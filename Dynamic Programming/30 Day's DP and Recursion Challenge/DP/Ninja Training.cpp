Recusrive :- 
#include <bits/stdc++.h>
int solve(int day , int last , vector < vector < int >> & points){
    if(day == 0){
        int maxi = 0;
        for(int task = 0 ; task < 3 ; task++){
            if(task != last){
                maxi = max(maxi , points[0][task]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for(int task = 0; task < 3 ; task++){
        if(task != last){
            int point = points[day][task] + solve(day - 1 , task , points);
            maxi = max(maxi , point);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    
    return solve(n - 1 , 3 , points);
}

Memoized :-
#include <bits/stdc++.h>
int solve(int day , int last , vector < vector < int >> & points , vector < vector < int >> & dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0 ; task < 3 ; task++){
            if(task != last){
                maxi = max(maxi , points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = 0;
    for(int task = 0; task < 3 ; task++){
        if(task != last){
            int point = points[day][task] + solve(day - 1 , task , points , dp);
            maxi = max(maxi , point);
        }
    }
    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector < vector < int >> dp(n , vector < int > (4 , -1));

    return solve(n - 1 , 3 , points , dp);
}

Tabulation :-
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector < vector < int >> dp(n , vector < int > (4 , 0));
    dp[0][0] = max(points[0][1] , points[0][2]);
    dp[0][1] = max(points[0][0] , points[0][2]);
    dp[0][2] = max(points[0][0] , points[0][1]);
    dp[0][3] = max(points[0][0] , max(points[0][1] , points[0][2]));
    for(int i = 1; i < n ; i++){
        for(int last = 0; last < 4 ; last++){
            dp[i][last] = 0;
            for(int task = 0; task <= 2; task++){
                if(task != last){
                    int activity = points[i][task] + dp[i - 1][task];
                    dp[i][last] = max(dp[i][last] , activity);
                }
            }
        }
    }
    return dp[n - 1][3];
}

Space optimization :-
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector < int > prev(4 , 0);
    prev[0] = max(points[0][1] , points[0][2]);
    prev[1] = max(points[0][0] , points[0][2]);
    prev[2] = max(points[0][0] , points[0][1]);
    prev[3] = max(points[0][0] , max(points[0][1] , points[0][2]));
    for(int i = 1; i < n ; i++){
        vector < int > temp ( 4 , 0);
        for(int last = 0; last < 4 ; last++){
            temp[last] = 0;
            for(int task = 0; task <= 2; task++){
                if(task != last){
                    int activity = points[i][task] + prev[task];
                    temp[last] = max(temp[last] , activity);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
