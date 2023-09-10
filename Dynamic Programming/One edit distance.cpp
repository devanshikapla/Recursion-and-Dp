/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool edit(string s , string t , vector < vector < int >> & dp){
    for(int i = 0 ; i <= s.size(); i++){
        dp[i][0] = i;
    }
    for(int j = 0 ; j <= t.size() ; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= s.size() ; i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min({dp[i - 1][j - 1] , dp[i][j - 1] , dp[j - 1][i]});
            }
        }
    }
    if(dp[s.size()][t.size()] == 1 ) return true;
    return false;
}
int main()
{
    string s;
    string t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vector < vector < int >> dp(n + 1 , vector < int > (m + 1 , -1));
    bool flag = true;
    flag = edit(s , t , dp);
    cout<<flag<<endl;

    return 0;
}
