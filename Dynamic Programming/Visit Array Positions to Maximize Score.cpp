class Solution {
public:
    long long dp[100005][3];
    long long solve(vector<int>& nums, int x , long long flag  , long long index){
        if(index >= nums.size()) return 0;

        if(dp[index][flag] != -1) return dp[index][flag];
        
        long long take = 0;
        //switch is only possible if current flag is not equal to previous flag 

        if(nums[index] % 2 != flag){
            take = nums[index] - x + solve(nums , x , !flag , index + 1);
        }

        long long notTake = 0;
        if(nums[index] % 2 == flag ){
            notTake = nums[index];
           
            
        }
        notTake += solve(nums , x , flag , index + 1);
        return dp[index][flag] = max(take , notTake);
    }
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();

        // i am going to take a flag variable that will be initilized to 0 as initially i am standing at 0 and i want the parity of 0th element

        memset(dp , -1 , sizeof(dp));
        long long flag = 0;
        //if nums[0] == odd put flag = 1 that is a switch happened 
        if(nums[0] % 2 == 1) {
            flag = 1;
        }
        long long ans = nums[0] + solve(nums , x , flag , 1);
        return ans;

    }
};
