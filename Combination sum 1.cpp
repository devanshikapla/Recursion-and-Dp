class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void fun(vector<int> &arr,int i, int k, vector<vector<int>> &ans,vector<int> &v){
        
        if(i==arr.size()){
            if(k==0) ans.push_back(v);
            return;
        }
        //pick the elemnet
        if(arr[i]<=k){
            v.push_back(arr[i]);
            fun(arr,i,k-arr[i],ans,v);
            v.pop_back();
        }
        
        fun(arr,i+1,k,ans,v);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin() , A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector < vector < int >> ans;
        vector < int > res;
        fun(A , 0 , B , ans , res);
        return ans;
    }
