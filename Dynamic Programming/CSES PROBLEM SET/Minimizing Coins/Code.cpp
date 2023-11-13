/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>


using namespace std;


void solve(){
    int n,x;
    cin>>n>>x;
    
    vector < int > ans(n);
    for(int i = 0 ; i < n ; i++){
        cin>>ans[i];
    }
    vector < int > dp(x + 1 , 1e9);
    
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n ; j++){
            if(ans[j] <= i){
                dp[i] = min(dp[i] , dp[i - ans[j]] + 1);
            }
        }
    }
    if(dp[x] < 1e9){
        cout<<dp[x]<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
int main()
{
    solve();

    return 0;
}
