class Solution {
public:
// declare a map to memoize things
    unordered_map < string , double > mpp;
    vector < pair < int , int >> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    double solve(int n , int k , int row , int col){
        //base cases
        //if row and column goes out of bound;
        if(row < 0 || row >= n || col < 0 || col >= n) return 0;
        //if k becomes 0 return 1;
        if(k == 0) return 1;

        string key = to_string(k) + "_" + to_string(row) + "_" + to_string(col);

        //memoization step 

        if(mpp.find(key) != mpp.end()) return mpp[key];

        double ans = 0;

        //dir movind recursion call in 8 directions;

        for(auto & it : dir){
            int newRow = row + it.first;
            int newCol = col + it.second;

            ans += (double)solve(n , k - 1 , newRow , newCol);
        }
        return mpp[key] = (double)(ans / 8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        return solve(n , k , row , column);
    }
};
