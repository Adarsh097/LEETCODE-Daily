class Solution {
public:
    bool isValid(int &row,int &col, char &val, vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col]==val)return false;
            if(i!=col && board[row][i]==val)return false;

            int r = (3*(row/3) + (i/3)), c = (3*(col/3) + (i%3));
            if(r!=row && c!=col && board[r][c]==val)return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isValid(i,j,board[i][j],board))return false;
                }
            }
        }
        return true;
    }
};