class Solution {
public:
   // directions vector for both rows;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    //find function
    bool find(vector<vector<char>>& board , int i , int j , string & word , int index , int n , int m){
        //base case
        if(index >= word.size()) return true;
        //out of bound case 
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[index]){
            return false;
        }
        char temp = board[i][j];
        //placing '$' in place of temp

        board[i][j] = '$';

        for(auto& it : directions){
            int dr = i + it[0];
            int dc = j + it[1];
            //recursive call;
            if(find(board , dr , dc , word , index + 1 , n , m)){
                return true;
            }

        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int size = word.length();
        if(m * n < size) return false;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                //if find fn return true
                if(board[i][j] == word[0] && find(board, i , j , word , 0, n , m)){
                    return true;
                }
            }
        }
        return false;
    }
};
