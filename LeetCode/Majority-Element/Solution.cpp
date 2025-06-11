class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0, cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                cnt++;
            }else{
               if(cnt==0){
                ele = nums[i];
                cnt = 1;
               }else{
                cnt--;
               }
            }
        }
        return ele;
    }
};