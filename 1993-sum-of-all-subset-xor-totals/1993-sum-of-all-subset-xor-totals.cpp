class Solution {
public:
    int sum = 0;
    void solve(vector<int>&nums,int ind,int temp){
        if(ind>=nums.size()){
            sum += temp;
            return;
        }
        solve(nums,ind+1,temp);

        temp ^= nums[ind];
        solve(nums,ind+1,temp);
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        solve(nums,0,0);
        return sum;
    }
};