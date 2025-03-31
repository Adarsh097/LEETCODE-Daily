class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i=0, j = nums.size()-1;
        int minPSum = 0;
        sort(nums.begin(),nums.end());
        while(i<j){
            int sum = nums[i]+nums[j];
            minPSum = max(minPSum,sum);
            i++;j--;
        }
        return minPSum;
    }
};