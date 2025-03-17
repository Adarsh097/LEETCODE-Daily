class Solution {
public:
    bool check(vector<int>&nums,int k,int mid){
        k-=1;
        int temp = mid;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(temp>=val){
                temp-=val;
            }else{
                if(k==0)return false;
                k-=1;
                temp = mid;
                if(temp<val)return false;
                temp-=val;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end()),
        high = accumulate(nums.begin(),nums.end(),0);

        int ans = high;
        while(low<=high){
            int mid  = low + ((high-low)>>1);
            if(check(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};