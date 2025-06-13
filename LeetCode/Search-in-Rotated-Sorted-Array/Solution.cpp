class Solution {
public:
   bool check(int sValue,int mValue){
    return mValue >= sValue;
   }
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int low = 0,  high = nums.size()-1;
        while(low<=high){
            int mid = ((high-low)>>1) + low;
            if(nums[mid] == target)return mid;

            if(check(nums[low],nums[mid])){
                if(nums[mid] > target && target >= nums[low]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(nums[mid] < target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return ans;
    }
};