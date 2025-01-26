class Solution {
public:
    set<vector<int>>s;
    vector<int>temp;
    void solve(vector<int>&nums,int ind,int &n){
        if(ind >= n){
            s.insert(temp);
            return;
        }

        temp.push_back(nums[ind]);
        solve(nums,ind+1,n);
        temp.pop_back();

        solve(nums,ind+1,n);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n =  nums.size();
        sort(nums.begin(),nums.end());
        solve(nums,0,n);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};