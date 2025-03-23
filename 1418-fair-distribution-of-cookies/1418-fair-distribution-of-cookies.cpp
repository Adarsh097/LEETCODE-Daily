class Solution {
public:
    vector<int>children;
    int ans =  INT_MAX;
    void solve(vector<int>&nums,int ind){
        if(ind == nums.size()){
            int maxi = *max_element(children.begin(),children.end());
            ans = min(maxi,ans);
            return;
        }

        int val = nums[ind];
        for(int i=0;i<children.size();i++){
            children[i] += val;
            solve(nums,ind+1);
            children[i] -= val;
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        children.resize(k,0);
        solve(cookies,0);
        return ans;
    }
};