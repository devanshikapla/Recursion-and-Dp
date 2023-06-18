 
    long long power(int a,int b)
    {
       //Your code here
        if(b == 0) return 1;
        long long temp = power(a , b / 2);
        temp = (temp * temp) % mod;
        if(b % 2 == 0){
            return temp;
        }
        return (temp * a )% mod;
        
    }
