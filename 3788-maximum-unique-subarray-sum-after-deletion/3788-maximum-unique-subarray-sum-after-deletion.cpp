class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        for(auto &val : nums){
            s.insert(val);
        }
        int sum = 0, mini = INT_MIN;
        for(auto &val : s){
            if(val>0)sum+=val;
            else{
                mini = max(mini,val);
            }
        }
        return (sum!=0)?sum:mini;
    }
};