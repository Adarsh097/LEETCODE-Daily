class Solution {
public:
    int ans = 0;
    bool isSafe(int row,int col,vector<string>&b){
        int n = b.size();
        //up 
        for(int i=row-1;i>=0;i--){
            if(b[i][col]=='Q')return false;
        }
        //up left;
        for(int i=row-1, j=col-1;i>=0 and j>=0;i--,j--){
            if(b[i][j]=='Q')return false;
        }
        //up right
        for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++){
            if(b[i][j]=='Q')return false;
        }
        return true;
    }

    void solve(int row,int &n,vector<string>b){
        if(row >= n){
            ans++;
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(row,col,b)){
                b[row][col] = 'Q';
                solve(row+1,n,b);
                b[row][col] = '.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        vector<string>b(n,string(n,'.'));
        solve(0,n,b);
        return ans;
    }
};