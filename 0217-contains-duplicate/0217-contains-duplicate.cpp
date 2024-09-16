class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s;
        for(auto val : nums){
            s.insert(val);
        }
        return nums.size() > s.size();
    }
};