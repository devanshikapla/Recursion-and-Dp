
    void solve(stack < int > & s , int k){
        if(k == 1){
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        solve(s , k - 1);
        s.push(temp);
        return;
    }
    void deleteMid(stack<int>&s, int n)
    {
       
        if(n == 0) return;
        int k = n / 2 + 1;
        solve( s , k);
    }
