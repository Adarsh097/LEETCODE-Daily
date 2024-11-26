class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>duplicates;
        int  i=0;
        while(i<n){
            int val = nums[i];
            if(val-1 == i){
                i++;
            }
            else if(nums[val-1] != val){
                swap(nums[i],nums[val-1]);
            }else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]-1 != i){
                duplicates.push_back(nums[i]);
            }
        }
        return duplicates;
    }
};