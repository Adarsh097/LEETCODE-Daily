class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0, cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele)cnt++;
            else{
                if(cnt==0){
                    cnt = 1;
                    ele = nums[i];
                }else{
                    cnt--;
                }
            }
        }
        return ele;
    }
};