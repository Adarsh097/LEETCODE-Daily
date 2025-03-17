class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        nums.push_back(1000);
        for(int i=0;i<nums.size()-1;i++){
            count++;
            if(nums[i]!=nums[i+1]){
                if((count&1)==1)return false;
                count = 0;
            }
        }
        return true;
    }
};