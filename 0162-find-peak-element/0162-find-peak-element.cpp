class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
       
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