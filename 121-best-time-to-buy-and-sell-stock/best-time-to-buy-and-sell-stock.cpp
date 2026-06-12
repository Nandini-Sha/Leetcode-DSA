class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int m = 0;
        for(auto sell:prices){
            m = max(m,sell-minBuy);
            minBuy = min(minBuy,sell);
        }

        return m;
    }
};