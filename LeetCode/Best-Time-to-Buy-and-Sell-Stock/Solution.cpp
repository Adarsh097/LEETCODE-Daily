class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        for(auto &val : prices){
            profit = max(profit,val-mini);
            mini = min(mini,val);
        }
        return profit;
    }
};