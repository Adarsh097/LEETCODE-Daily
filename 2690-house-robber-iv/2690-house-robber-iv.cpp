class Solution {
public:
    int check(vector<int>&nums,int &k, int mid){
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end()),
        high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = (high - low)/2 + low;
            if(check(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};