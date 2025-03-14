class Solution {
public:
    bool check(vector<int>&nums,int &maxOp,int &mid){
        long long count = 0, i = 0;
        while(i<nums.size()){
            count += (long  long)nums[i]/mid;
            if(nums[i]%mid==0)count--;
            i++;
        }
        return count <= maxOp;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = (high-low)/2 + low;
            if(check(nums,maxOperations,mid)){
                ans = mid;
                high =  mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};