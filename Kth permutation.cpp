
class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        int fac=1;
       
        vector<int>numbers;
        for(int i=1; i<n; i++){
            fac=fac*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
     
        string ans="";
        k=k-1;
        while(true){
            int x= k/fac;
            ans=ans+ to_string(numbers[x]);
            numbers.erase(numbers.begin()+x);
            
            if(numbers.size()==0) break;                    
            k=k%fac;      
            fac=fac/numbers.size();
        }
        return ans;
    }
};
