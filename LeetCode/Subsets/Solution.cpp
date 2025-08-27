class Solution {
public:
     vector<vector<int>>ans;
      vector<int>temp;
     void solve(vector<int>&nums,int ind){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(nums,i+1);
            temp.pop_back();
        }
        return;
     }
    vector<vector<int>> subsets(vector<int>& nums) {
       
        solve(nums,0);
        return ans;
    }
};