class Solution {
public:
   
    int rob(vector<int>& nums) {
        int n=nums.size()-1;

        //if index get negative
        int prev2=0;
        if(n<0)return prev2;
        //for only one house
        int prev1=nums[0];
        if(n==0)return prev1;

        int curr;
        for(int i=1;i<=n;i++){
    
        //include
        int include=nums[i] + prev2;
        //exclude
        int exclude= 0 + prev1;
        //storing the ans
        curr = max(include,exclude);

        prev2=prev1;
        prev1=curr;
        }
        return curr;
    }
};