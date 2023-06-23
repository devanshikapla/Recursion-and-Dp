#include <bits/stdc++.h> 
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code 
	vector < int > prev(maxWeight + 1 , 0) , curr(maxWeight + 1 , 0);

	//vector < vector < int >> dp( n , vector < int > ( maxWeight + 1 , 0));
	for(int W = wt[0] ; W <= maxWeight; W++){
		prev[W] = val[0];
	}
	for(int index = 1 ; index < n ; index++){
		for(int W = 0 ; W <= maxWeight ; W++){
			int notTake = prev[W];
			int take = INT_MIN;
			if(wt[index] <= W){
				take = val[index] + prev[W - wt[index]];

			}
           curr[W] = max(take , notTake);
		}
		prev = curr;
	}
	return prev[maxWeight];
}
