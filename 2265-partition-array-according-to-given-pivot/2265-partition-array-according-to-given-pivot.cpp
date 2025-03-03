class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int s = 0, e = n - 1;
        vector<int>ans(n,pivot);
        for(auto &val : nums){
            if(val < pivot){
            ans[s] = val;
            s++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>pivot){
                ans[e] = nums[i];
                e--;
            }
        }
        return ans;
    }
};