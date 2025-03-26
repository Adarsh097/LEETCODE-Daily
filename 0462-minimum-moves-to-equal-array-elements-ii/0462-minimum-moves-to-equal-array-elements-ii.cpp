class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(),nums.begin()+(n/2),nums.end());
        int medianTarget = nums[n/2];
        int minMoves = 0;
        for(auto &val : nums){
            minMoves += abs(val-medianTarget);
        }
        return minMoves;
    }
};