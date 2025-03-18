class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int len = 0, mask = 0;
        int i=0,j=0;
        while(j<nums.size()){
            while((mask & nums[j]) != 0){
                mask ^= nums[i];
                i++;
            }
            len = max(len,j-i+1);
            mask |= nums[j];
            j++;
        }
        return len;
    }
};