#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.
	  vector < int > dp1(n , 1);
	  vector < int > dp2(n , 1);
	  for(int i = 0 ; i <= n - 1 ; i++){
		  for(int prevIndex = 0 ; prevIndex <= i - 1; prevIndex++){
			  if(arr[prevIndex] < arr[i]){
				  dp1[i] = max(dp1[i] , 1 + dp1[prevIndex]);
			  }
		  }
	  }	   
	  for(int i = n - 1; i >= 0 ; i--){
		  for(int prevIndex = n -1 ; prevIndex > i ; prevIndex--){
			  if(arr[prevIndex] < arr[i]){
				  dp2[i] = max(dp2[i] , 1 + dp2[prevIndex]);
			  }
		  }

	}
	int maxi = -1;
	for(int i = 0 ; i < n ; i++){
		maxi = max(maxi , dp1[i] + dp2[i] - 1);
	}
	return maxi;
} 
