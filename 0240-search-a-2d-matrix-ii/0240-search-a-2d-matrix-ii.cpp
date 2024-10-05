class Solution {
public:
    bool solve(vector<int>&arr,int target){
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(arr[mid] == target)return true;
            else if(arr[mid]>target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(solve(matrix[i],target)){
                return true;
            }
        }
        return false;
    }
};