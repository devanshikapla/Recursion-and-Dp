class Solution {
public:
    void solve(int index , int target , vector < int > & nums , vector < int > & res ,
       int k , vector < vector < int >> & ans){
           //base condition;
           if(target == 0 ){
               if(res.size() == k){
                   ans.push_back(res);
                   return;
               }
           }
           for(int i = index ; i < nums.size() ; i++){
               //to avoid duplicates;
               if(i > index && nums[i] == nums[i - 1]) continue;
               if(nums[i] <= target){
                   res.push_back(nums[i]);
                   //take
                   solve(i + 1 , target - nums[i] , nums , res , k , ans);
                   res.pop_back();
               }
           }
       }
    vector<vector<int>> combinationSum3(int k, int n) {
        //Ans matrix
        vector < vector < int >> ans;
        vector < int > nums;
        for(int i = 1 ; i <= 9 ; i++){
            nums.push_back(i);

        }
        //to store intermediate steps during recursion
        vector < int > temp;
        solve(0 , n , nums , temp , k , ans);
        return ans;
    }
};
