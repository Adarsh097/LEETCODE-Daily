class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //1. Remove the out of range values in the array: range -> [1,n]
        //2. mark the corresponding index as negative when it is positive
        //3. then, the first positive element will give the answer
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<1 || nums[i]>n){
                nums[i] = n+1;
            }
        }

        for(int i=0;i<n;i++){
            int ind = abs(nums[i]) - 1;
            if(ind>=0 && ind<n && nums[ind]>0){
                nums[ind]*=-1;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0)return i+1;
        }
        return n+1;
    }
};