class Solution {
public:
    void solve(int val, int num,vector<int>&ans){
        if(val > num){
            return;
        }
        ans.push_back(val);
        for(int i=0;i<=9;i++){
            int newNum = val*10 + i;
            if(newNum <= num){
                solve(newNum,num,ans);
            }
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};