class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans =  -1;
        for(int i=nums.size()-1;i>=0;i--){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]++;
            }else{
                ans = i;
                break;
            }
        }
        return int(ceil((ans+1)/3.0));
    }
};