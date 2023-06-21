#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int mini = prices[0];
    int profit = 0;
    int maxi = 0;
    for(int i = 0 ; i < n ; i++){
        profit = prices[i] - mini;
        maxi = max(maxi , profit);
        mini = min(prices[i] , mini);
    }
    return maxi;
}
