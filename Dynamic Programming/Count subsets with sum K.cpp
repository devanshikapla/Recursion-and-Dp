//Recursion
int solve(int index , int target , vector<int>& arr, vector<vector<int>> &dp){
	if(target == 0) return 1;
	if(index == 0) return arr[0] == target;
	if(dp[index][target] != -1){
		return dp[index][target];
	}
	int notTaken = solve(index - 1 , target , arr , dp);
	int taken = 0;
	if(arr[index] <= target) taken = solve(index - 1 , target - arr[index] , arr , dp);
	return dp[index][target] = taken + notTaken;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector < vector < int >> dp(n , vector < int > (k + 1  , -1));
	return solve(n - 1 , k , arr , dp);

}
//Tabulation
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector < vector < int >> dp(n , vector < int > (k + 1  , 0));
	for(int i = 0 ; i < n ; i++){
		dp[i][0] = 1;
	}
	if(arr[0] <= k){
		dp[0][arr[0]] = 1;
		
	}
	for(int index = 1; index < n ; index++){
		for(int target = 1; target <= k ; target++){
			int notTaken = dp[index - 1][target];
			int taken = 0;
			if(arr[index] <= target) taken = dp[index - 1][target - arr[index]];
			dp[index][target] = notTaken + taken;

		}
	}
    return dp[n - 1][k];
}
//space optimization
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	//vector < vector < int >> dp(n , vector < int > (k + 1  , 0));
	vector < int > prev(k + 1, 0);
	prev[0] = 1;
	
	if(arr[0] <= k){
		prev[arr[0]] = 1;
		
	}
	for(int index = 1; index < n ; index++){
		vector < int > curr ( k + 1 , 0);
		curr[0] = 1;
		for(int target = 1; target <= k ; target++){
			int notTaken = prev[target];
			int taken = 0;
			if(arr[index] <= target) taken = prev[target - arr[index]];
			curr[target] = notTaken + taken;

		}
		prev = curr;
	}
    return prev[k];
}
