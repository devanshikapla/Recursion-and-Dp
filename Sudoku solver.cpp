public:
    bool isvalid(int grid[N][N],int row,int col,int val){
        for(int i=0;i<N;i++){
            if(grid[i][col]==val) return false;
            if(grid[row][i]==val) return false;
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3] == val) return false;
        }
        return true;
    }
    bool solve(int grid[N][N]){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(int c=1;c<=9;c++){
                        if(isvalid(grid,i,j,c)){
                            grid[i][j]=c;
                            if(solve(grid)) return true;
                            else grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<' ';
            }
        }
    }
