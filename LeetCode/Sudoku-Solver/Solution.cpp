class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char val){
        for(int i=0;i<9;i++){
            // row check
            if(board[i][col] == val)return false;

            // col check
            if(board[row][i]==val)return false;

            // 3x3 grid check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
               for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                //check if the cell is empty
                if(board[row][col] == '.'){
                    //check if it is safe
                    for(int val='1';val<='9';val++){
                    if(isSafe(board,row,col,val)){
                        board[row][col] = val;
                        // do recursion for the rest
                        if(solve(board)){
                            return true;
                        }
                            //backtrack
                            board[row][col] = '.';
                        

                    }

                    }
                    return false;
                }
                // hamne har ek value ke liye check karliya but, possilbe nahi hai
                
            }
        }
        // solve entire sudoku
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        (solve(board));
    }
};