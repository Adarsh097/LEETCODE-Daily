class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
     int i=0;
     int j=0;
     long long n = nums.size();
     int count = 0;
     int maxi = INT_MIN;
     long long  ans = 0;
     for(int i=0;i<n;i++){
        maxi = max(maxi,nums[i]);
     }
     while(j<n){
        //expand till valid window
        if(nums[j]==maxi){
            count++;
        }
        //now shrink to make window valid
        while(count>=k){
            ans+=(n-j);
            if(nums[i]==maxi){
                count--;
            }
            i++;
        }

        j++; 
     }   
     return ans;
    }
};