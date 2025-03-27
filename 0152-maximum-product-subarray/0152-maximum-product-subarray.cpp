class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int temp = 1;
            for(int j=i;j<n;j++){
                temp*=nums[j];
                ans = max(ans,temp);
            }
            
        }
        return ans;
    }
};