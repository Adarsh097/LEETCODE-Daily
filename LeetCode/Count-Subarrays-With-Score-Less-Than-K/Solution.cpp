class Solution {
public:
    long long solve(vector<int>&nums,long long k){
        long long i=0,j=0,sum = 0,prod = 1,cnt = 0;
        while(j<nums.size()){
            sum += nums[j];
            prod = sum*(j-i+1);
            while(prod>k){
                if(i==j){
                    i++;
                    sum = 0;
                    prod = 1;
                    break;
                }
                sum -= nums[i];
                i++;
                prod = sum*(j-i+1);
               
            }
            cnt += (j-i+1);
            j++;

        }
        return cnt;

    }
    long long countSubarrays(vector<int>& nums, long long k) {
     long long ans = solve(nums,k-1);
     return ans;   
    }
};