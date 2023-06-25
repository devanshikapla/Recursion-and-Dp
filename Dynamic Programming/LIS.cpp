#include<bits/stdc++.h>
int solve(int arr[] , int n , int index , int prevIndex
   , vector < vector < int >> & dp){
    if(index == n) return 0;
    int notTake = solve(arr , n , index + 1 , prevIndex , dp);
    int Take = 0;
    if(prevIndex == -1 || arr[index] > arr[prevIndex]){
        Take = 1 + solve(arr , n , index + 1 , index , dp);
    }
    return dp[index][prevIndex + 1] = max(Take , notTake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector < vector < int >> dp(n , vector < int > (n + 1 , -1));
    return solve(arr , n , 0 , -1 , dp);
}
