class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>result(n+1,0);
        for(auto &q : queries){
            int lb  = q[0], ub = q[1];
            result[lb]++;
            result[ub+1]--;
        }
        for(int i=1;i<=n;i++){
            result[i] += result[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>result[i])return false;
        }
        return true;
    }
};