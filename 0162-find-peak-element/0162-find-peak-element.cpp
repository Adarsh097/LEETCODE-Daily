class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        if(n==2){
            if(nums[0]>nums[1])return 0;
            else if(nums[1]>nums[0])return 1;
        }
        int s = 0 , e = nums.size()-1;
        int ans = -1;
        while(s<e){
            int mid = (e-s)/2 + s;
            if(nums[mid]<nums[mid+1]){
                s = mid+1;
            }else{
                e = mid;
            }
        }
        return s;
    }
};