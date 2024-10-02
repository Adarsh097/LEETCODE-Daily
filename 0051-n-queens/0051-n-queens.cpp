class Solution {
public:
    bool isSafe(int col, int row, vector<string>&b){
        int n = b.size();
        //up
        for(int r = row-1;r>=0; r--){
            if(b[r][col] == 'Q')return false;
        }

        // up - left
        for(int r=row-1, c=col-1; r>=0 and c>=0; r--,c--){
            if(b[r][c] == 'Q')return false;
        }

        //up -right
        for(int r=row-1, c= col+1; r>=0 and c<n; c++,r--){
            if(b[r][c] == 'Q')return false;
        }
        return true;
    }
    vector<vector<string>>ans;
    void solve(int row, int n, vector<string>&b){
        if(row >= n){
            ans.push_back(b);
            return;
        }

        for(int col = 0;col<n;col++){
            if(isSafe(col,row,b)){
                b[row][col] = 'Q';
                solve(row+1,n,b);
                //backtracking
                b[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(0,n,board);
        return ans;
    }
};