void insert(stack <int> & s , int top){
        if(s.size() == 0){
            s.push(top);
            return;
            
        }
        int temp = s.top();
        s.pop();
        insert(s , top);
        s.push(temp);
    }
    void Reverse(stack<int> &st){
        if(st.size() == 0) return;
        int temp = st.top();
        st.pop();
        Reverse(st);
        insert(st , temp);
    }
