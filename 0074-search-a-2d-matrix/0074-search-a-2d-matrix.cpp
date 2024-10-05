class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int e = matrix.size() * matrix[0].size()-1;
        int colSize = matrix[0].size();
        while(s<=e){
            int mid = (e-s)/2 + s;
            int row = mid/colSize;
            int col = mid%colSize;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col]>target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return false;

    }
};