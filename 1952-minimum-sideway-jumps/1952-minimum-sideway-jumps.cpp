class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&obs,int pos,int ind){
        if(ind == obs.size()-1)return 0;

        if(dp[ind][pos]!=-1)return dp[ind][pos];

        
        if(obs[ind+1]!=pos || obs[ind+1]==0){
            return dp[ind][pos] = solve(obs,pos,ind+1);
        }else{
            int temp = INT_MAX;
            for(int i = 1;i<=3;i++){
                if(obs[ind]!=i && i != pos){
                    temp = min(temp,1 + solve(obs,i,ind));
                }
            }
            return dp[ind][pos] = temp;
        }
       
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        dp.resize(n+1,vector<int>(4,-1));
        int jumps = solve(obstacles,2,0);
        return jumps;
    }
};