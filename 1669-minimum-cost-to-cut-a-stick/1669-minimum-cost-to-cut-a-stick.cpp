class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&cuts,int i,int j){
        if(i>j)return 0;

        if(dp[i][j]!= -1)return dp[i][j];

        int minCost = INT_MAX;
        for(int k=i;k<=j;k++){
            int cost = (cuts[j+1]-cuts[i-1]) + solve(cuts,i,k-1) + solve(cuts,k+1,j);
            minCost = min(minCost,cost);
        }
        return dp[i][j] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        dp.resize(size+3,vector<int>(size+3,-1));
        int ans = solve(cuts,1,size);
        return ans;
    }
};