class Solution {
public:
    int lowerBound(vector<int>& nums,int target){
        int s = 0, e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }else if(nums[mid]>target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
        int upperBound(vector<int>& nums,int target){
        int s = 0, e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }else if(nums[mid]>target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums,target);
        if(lb==-1)return {-1,-1};
        int ub = upperBound(nums,target);
        return {lb,ub};
    }
};