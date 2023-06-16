
    void solve(int index , int n , int sum , vector < int > & arr , vector < int > & ans){
        if(index == n){
            ans.push_back(sum);
            return;
        }
        //Take call;
        solve(index + 1 , n , sum  + arr[index] ,arr, ans);
        //Not take call
        solve(index + 1 , n , sum ,arr, ans);
        
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector < int > ans;
        solve(0 , n , 0 , arr, ans);
        return ans;
    }
