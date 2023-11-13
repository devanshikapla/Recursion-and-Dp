#include <iostream>
#include <bits/stdc++.h>
 
 
using namespace std;
 
int mod = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector < int > dp(n + 1);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= 6; j++){
            if(j <= n - i){
                dp[i] = (dp[i] + dp[i + j]) % mod;
            }
        }
    }
    cout<<dp[0]<<endl;
}
int main()
{
    solve();
    
    
 
    return 0;
}
