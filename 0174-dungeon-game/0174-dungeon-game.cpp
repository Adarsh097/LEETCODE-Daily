class Solution {
public:
    int m,n;
    int dp[201][201];
    int solve(vector<vector<int>>&arr,int i,int j){
        if(i==m-1 && j==n-1){
           return (arr[i][j]<=0)?1 - arr[i][j] : 1;
        }

        if(i>=m || j>=n)return 1e9;

        if(dp[i][j]!=-1)return dp[i][j];

        int minHealthReqRight = solve(arr,i,j+1);
        int minHealthReqDown = solve(arr,i+1,j);

        //we choose the min health path
        // sub : if arr[i][j] is -ve then, it will add up the min health req or if it is +ve then, it will decrese the min health required
        int minHealthFromCurrPos = min(minHealthReqRight,minHealthReqDown) - arr[i][j];

        // from curr cell if minHealthFromCurrPos <=0 -> 1 is req only
        return dp[i][j] = (minHealthFromCurrPos<=0)?1:minHealthFromCurrPos;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size(), n = dungeon[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(dungeon,0,0);
    }
};