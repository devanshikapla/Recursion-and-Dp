class Solution {
public:
    bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ;
        int target ;
        if(n == 1) return false;
        for(auto it : nums){
            sum = sum + it;
        }
        if(sum % 2 != 0) return false;
        else{
            target  = sum / 2;

        }
        vector<vector<int>>dp( n ,vector<int>(target+1,-1));
        return subsetSumUtil( n - 1 , target , nums , dp);
    }
};
