class Solution {
public:
    bool check(int ele,int tar){
        return tar <= ele;
    }
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size();
        int low = 0, high = ans-1;

        while(low<=high){
            int mid = ((high-low)>>2) + low;

            if(check(nums[mid],target)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};