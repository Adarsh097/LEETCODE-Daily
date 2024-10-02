class Solution {
public:
    bool isSafe(int row, int col, vector<string>&b){
        int n = b.size();
        //up
        for(int r = row-1;r >=0 ;r--){
            if(b[r][col] == 'Q')return false;
        }

        // up left
        for(int r=row-1, c=col-1; r>=0 and c>=0; r--,c--){
            if(b[r][c] == 'Q')return false;
        }

        // up right
        for(int r=row-1, c=col+1; c<n and r>=0; r--,c++){
            if(b[r][c] == 'Q')return false;
        }
        return true;
    }
    int ans = 0;
    void solve(int row,vector<string>&b,int n){
        if(row >= n){
            // one board is solved
            ans += 1;
            return;
        }

        // try to solve
        for(int col = 0; col < n; col++){
            if(isSafe(row,col,b)){
                b[row][col] = 'Q';
                solve(row+1,b,n);
                b[row][col] = '.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(0,board,n);
        return ans;
    }
};