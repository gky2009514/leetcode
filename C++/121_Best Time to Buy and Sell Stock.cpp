class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        int mi = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - mi);
            mi = min(prices[i], mi);
        }
        return profit;
    }
};