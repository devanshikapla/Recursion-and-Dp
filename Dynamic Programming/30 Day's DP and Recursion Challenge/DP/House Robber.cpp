ecursive :-
 class Solution {
 public:
     int solve(int index , vector < int > & nums ){
         if(index == 0) return nums[index];
         if(index < 0) return 0;
         int pick = nums[index] + solve(index - 2 , nums);
         int notPick = solve(index - 1 , nums);
         return max(pick , notPick);
     }
     int rob(vector<int>& nums) {
         int n = nums.size();
         return solve(n - 1 , nums);
     }
 };
 Memoized :- 
 class Solution {
 public:
     int solve(int index , vector < int > & nums , vector < int > & dp ){
         if(index == 0) return nums[index];
         if(index < 0) return 0;
         if(dp[index] != -1) return dp[index];
         int pick = nums[index] + solve(index - 2 , nums , dp);
         int notPick = solve(index - 1 , nums , dp);
         return dp[index] = max(pick , notPick);
     }
     int rob(vector<int>& nums) {
         int n = nums.size();
         vector < int > dp ( n + 1 , -1);
         return solve(n - 1 , nums , dp);
     }
 };
 Tabulation :- 
 class Solution {
 public:

     int rob(vector<int>& nums) {
         int n = nums.size();
         vector < int > dp ( n + 1 , 0);
         dp[0] = nums[0];
         int pick;
         int notPick; 
         for(int i = 1; i < n ; i++){
             pick = nums[i];
             if(i > 1){
                 pick = pick + dp[i - 2];

             }
             notPick = dp[i - 1];
             dp[i] = max(pick , notPick);
         }
         return dp[n - 1];
     }
 };
 Space Optimized :- 
   class Solution {
 public:

     int rob(vector<int>& nums) {
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
 };
