class Solution {
public:
    bool check(vector<int>&nums,int mid){
        return nums[mid]<nums[0];
    }
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1, ans = 0;
        while(low<=high){
            int mid = (high-low)/2 + low;
            if(check(nums,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return nums[ans];
    }
};