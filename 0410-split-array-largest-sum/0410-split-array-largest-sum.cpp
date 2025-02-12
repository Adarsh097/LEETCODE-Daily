class Solution {
public:
    bool check(vector<int>&arr,int k,int sum){
        int temp = sum;
        k-=1;
        for(int i=0;i<arr.size();i++){
            int val = arr[i];
            if(temp>=val){
                temp-=val;
            }else{
                if(k==0)return false;
                k--;
                temp = sum;
                if(temp<val)return false;
                temp -= val;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low<=high){
            int mid = (high-low)/2 + low;

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