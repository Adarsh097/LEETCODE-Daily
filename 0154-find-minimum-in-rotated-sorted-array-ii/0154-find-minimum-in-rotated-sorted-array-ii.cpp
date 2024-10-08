class Solution {
public:
    int findMin(vector<int>& nums) {
     int s = 0;
     int e = nums.size()-1;
     int ans = 50001;
     while(s<=e){
        if(nums[s] < nums[e]){
            ans = min(ans,nums[s]);
            break;
        }
        int mid = (e-s)/2 + s;
        if(nums[mid] == nums[s] && mid != s){
            s++;
            continue;
        }
        if(nums[mid] >= nums[s]){
            ans = min(ans,nums[s]);
            s = mid+1;
        }else{
            ans = min(ans,nums[mid]);
            e = mid-1;
        }
     }   
     return ans;
    }
};