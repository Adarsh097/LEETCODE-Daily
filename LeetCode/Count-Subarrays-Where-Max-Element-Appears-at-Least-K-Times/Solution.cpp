class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
     long long cnt = 0, i = 0, j = 0, ans = 0, n = nums.size();
     long long maxEle = *max_element(nums.begin(),nums.end());
        while(j<nums.size()){
            if(nums[j]==maxEle)cnt++;
            while(cnt >= k){
                ans += (n-j);
                if(nums[i]==maxEle)cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};