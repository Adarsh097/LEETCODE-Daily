class Solution {
public:

    
    int solve(vector<int>& prices, int ind, int& n, int buy, int count, vector<vector<vector<int>>>& arr) {
        if (ind >= n || count==0)
            return 0;
        
        if(arr[ind][buy][count] != -1)return arr[ind][buy][count];
       
        long profit = 0;
        if (buy == 0) {
            profit = max(0 + solve(prices, ind + 1, n, 0, count,arr),
                         -prices[ind] + solve(prices, ind + 1, n, 1, count,arr));
        } else {
            profit = max(0 + solve(prices, ind + 1, n, 1, count,arr),
                         prices[ind]  + solve(prices, ind + 1, n, 0, count-1,arr));
        }
        return arr[ind][buy][count] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       
         vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(3, -1))
    );
        int profit = solve(prices,0,n,0,2,dp);
        return profit;
    }
};