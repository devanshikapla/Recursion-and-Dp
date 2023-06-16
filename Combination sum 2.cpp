class Solution {
public:
    void solve(int index , int target , vector < int > & arr , vector < int > & res , vector < vector < int >> & ans){
        if(target == 0){
            ans.push_back(res);
            return;
        }
        for(int i = index ; i < arr.size() ; i++){
            if(i > index && arr[i] == arr[i - 1]) continue;
            if(arr[i] > target) break;
            res.push_back(arr[i]);
            solve(i + 1 , target - arr[i] , arr , res , ans);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector < vector < int >> ans;
        sort(candidates.begin() , candidates.end());
        vector < int > res;
        solve(0 , target , candidates ,  res , ans);
        return ans;
    }
};
