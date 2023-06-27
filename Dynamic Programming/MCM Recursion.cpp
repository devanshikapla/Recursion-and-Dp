#include <bits/stdc++.h> 

int solve(vector < int > & arr , int i , int j){
    if(i == j) return 0;
    int mini = INT_MAX;
    for(int k = i ; k <= j - 1 ; k++){
        int ans = solve(arr , i , k ) + solve(arr , k + 1 , j) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini , ans);
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    return solve(arr , 1 , N - 1);
}
