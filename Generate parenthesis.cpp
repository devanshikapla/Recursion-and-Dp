class Solution
{
    public:
    void solve(string s,int open,int close,vector<string>& ans)
    {
        if(open==0 && close ==0)
        {
            ans.push_back(s);
            return;
        }
        if(open !=0)
        {
            s.push_back('(');
            solve(s,open-1,close,ans);
            s.pop_back();
        }
        if(close > open)
        {
            s.push_back(')');
            solve(s,open,close-1,ans);
            s.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector < string > ans;
        int open = n;
        int close = n;
        string output = "";
        solve(output , open , close  , ans);
        return ans;
    }
};
