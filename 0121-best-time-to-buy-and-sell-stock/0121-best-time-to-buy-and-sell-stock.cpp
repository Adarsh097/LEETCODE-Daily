class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int start = INT_MAX;
        int s = 0;
        int e = 0;
        while(e<prices.size()){
            if(prices[e] <= start){
                s = e;
                start = prices[e];
            }else{
                int profit = prices[e] - start;
                ans = max(ans,profit);
            }
            e++;
        }
        return ans;
    }
};