#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = nums[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = nums[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    vector < int > ans1;
    vector < int > ans2;
    for(int i = 0 ; i < n ; i++){
        if(i != 0) ans1.push_back(valueInHouse[i]);
        if(i != n - 1)ans2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(ans1) , maximumNonAdjacentSum(ans2));

}
