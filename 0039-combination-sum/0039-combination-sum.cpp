class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;

    void solve(vector<int>&arr,int &n, int ind, int target){
        if(target == 0){
            // one ans found
            ans.push_back(temp);
            return;
        }
        if(target<0)return;

        for(int i = ind;i<n;i++){
            temp.push_back(arr[i]);
            solve(arr,n,i,target - arr[i]);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
       
        solve(candidates,n,0,target);
        return ans;
    }
};