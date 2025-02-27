class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(m.find(val)==m.end())m[val]=i;
            else{
                if(i-m[val]<=k)return true;
                m[val] = i;
            }
        }
        return false;
    }
};