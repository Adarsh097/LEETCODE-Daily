class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            else if(nums[mid] >= nums[s]){
                //left half
                if(nums[mid]>target && target >= nums[s]){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }else{
                if(nums[mid]<target && target < nums[s]){
                    s = mid+1;
                }else{
                    e = mid-1;
                }
            }
        }
        return ans;
    }
};