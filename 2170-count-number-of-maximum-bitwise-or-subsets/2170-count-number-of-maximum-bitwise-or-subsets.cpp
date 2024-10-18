class Solution {
public:
    void count(int &ans,vector<int>&nums,int target,int ind, int &size,int bitwise){
       
        if(ind >= size){
             if(bitwise == target){
            ans++;
        }
        return;
        }

        //take 
        count(ans,nums,target,ind+1,size,bitwise|nums[ind]);

        //not take
        count(ans,nums,target,ind+1,size,bitwise);
        return;

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxBitwise = 0;
        for(auto &val : nums){
            maxBitwise |= val;
        }
        int n = nums.size();
        int ans = 0;
        int bitwise = 0;
        count(ans,nums,maxBitwise,0,n,bitwise);
        return ans;
    }
};