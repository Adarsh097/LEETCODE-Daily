class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(vector<int>& nums,int ind,int &n){
        ans.push_back(temp);
        for(int i=ind;i<n;i++){
            temp.push_back(nums[i]);
            solve(nums,i+1,n);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        solve(nums,0,n);
        return ans;
    }
};