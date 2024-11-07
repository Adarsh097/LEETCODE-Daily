class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int noOfBits = floor(log2(10000000)) + 1;
        // vector<int>v(24,0); 
        vector<int>v(noOfBits,0); 
        int n = candidates.size();
        for(int i=0;i<n;i++){
            int val = candidates[i];
            int ind = 0;
            while(val){
                if(val&1)v[ind]++;
                val = val >> 1;
                ind++;
            }
        }
        int ans = 1;
        for(auto &val : v){
            ans = max(ans,val);
        }
        return ans;
    }
};