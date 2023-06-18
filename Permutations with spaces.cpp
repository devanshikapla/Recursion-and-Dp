 void solve(vector < string > & ans , string s , string & out){
        if(s.length() == 0){
            ans.push_back(out);
            return;
        }
        string out1 = out;
        string out2 = out;
        out1.push_back(' ');
        out1.push_back(s[0]);
        out2.push_back(s[0]);
        s.erase(s.begin() + 0);
        solve(ans , s , out1);
        solve(ans , s , out2);
    }
    vector<string> permutation(string s){
        // Code Here
        vector < string > ans;
        string out = "";
        out.push_back(s[0]);
        s.erase(s.begin() + 0);
        solve(ans , s , out);
        return ans;
    }
