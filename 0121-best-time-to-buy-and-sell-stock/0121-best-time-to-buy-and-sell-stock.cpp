class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mProfit = 0;
        int start = INT_MAX;

        int s = 0;
        int e = 0;
        while(e<prices.size()){
            if(prices[e] <= start){
                start = prices[e];
                s = e;
            }else{
                int profit = prices[e] - start;
                mProfit = max(profit,mProfit);
            }
            e++;
        }
        return mProfit;
    }
};