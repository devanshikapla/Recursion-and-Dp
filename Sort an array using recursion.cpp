class Solution {
public:
    vector < int > insertAt(vector < int > & ans , int value){
        int n = ans.size();
        if(n == 0 || ans[n - 1] <= value) {
            ans.push_back(value);
            return ans;
        }
        int last = ans[n - 1];
        ans.pop_back();
        insertAt(ans , value);
        ans.push_back(last);
        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        int last = nums[n - 1];
        nums.pop_back();
        vector < int > temp = sortArray(nums);
        vector < int > sorted = insertAt(temp , last);
        return sorted;
    }
};
