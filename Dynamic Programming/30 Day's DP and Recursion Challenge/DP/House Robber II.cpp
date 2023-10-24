class Solution {
public:   
    int solve(vector<int>& nums ) {
        int n = nums.size();
        
        int prev = nums[0];
        int prev2 = 0;
        int pick;
        int notPick; 
        for(int i = 1; i < n ; i++){
            pick = nums[i];
            if(i > 1){
                pick = pick + prev2;

            }
            notPick = prev;
            int curr = max(pick , notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector < int > nums1;
        vector < int > nums2;
        if(n == 1) return nums[0];
        for(int i = 0 ; i < n - 1 ; i++)
        {
            nums1.push_back(nums[i]);
        }
        for(int i = 1; i < n ; i++){
            nums2.push_back(nums[i]);
        }
       
        int taken = solve( nums1 );
        int notTaken = solve(nums2);
        return max(taken , notTaken);
    }
};
