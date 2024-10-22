class Solution {
public:
    bool isSafe(vector<vector<int>>& matrix,int &row, int &col, int &val){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            // row
            if(i!=row && matrix[i][col]==val)return false;

            //col
            if(i!=col && matrix[row][i]==val)return false;
        }
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row=0;row<n;row++){
            for(int col = 0;col<n;col++){
                int val = matrix[row][col];
                if(!isSafe(matrix,row,col,val))return false;
            }
        }
        return true;
    }
};