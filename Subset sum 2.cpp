
class Solution {

  public:
    void Solve(int index, vector<int> &ds, vector<int> &arr, vector<vector<int> > &res) {
        res.push_back(ds);
    
        for(int i=index; i<arr.size(); i++) {
    
            if(i>index && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            Solve(i+1, ds, arr, res);
            ds.pop_back();
        }
    
        return;
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        vector < vector < int >> res;
        vector < int > ans;
        sort(nums.begin(), nums.end());
        Solve(0 , ans , nums , res);
        return res;
        
    }
};
