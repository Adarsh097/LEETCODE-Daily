class Solution {
public:
    vector<vector<string>>ans;
    bool isSafe(int row,int col,vector<string>&board){
        //up
        for(int i=row-1;i>=0;i--){
            if(board[i][col] == 'Q')return false;
        }

        //up left
        for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }

        //upright
        for(int i=row-1,j=col+1;i>=0 and j<board.size();i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    void solve(int row, int &n,vector<string>v){
        if(row >=n){
            ans.push_back(v);
            return;
        }

        for(int col = 0;col<n;col++){
            if(isSafe(row,col,v)){
                v[row][col] = 'Q';
                solve(row+1,n,v);
                v[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>v(n,string(n,'.'));
        solve(0,n,v);
        return ans;
    }
};