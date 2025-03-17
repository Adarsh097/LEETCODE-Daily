class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int arr[501];
        for(auto &val : nums){
            arr[val]++;
        }
        for(int i=0;i<501;i++){
            if((arr[i]&1)==1)return false;
        }
        return true;
    }
};