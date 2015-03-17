class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int pos = (int)prices.size() - 1;
        int profit = 0;
        while (pos > 0) {
            int sp = findSell(prices, pos);
            if (sp <= 0)
                break;
            int bp = findBuy(prices, sp);
            profit += prices[sp] - prices[bp];
            pos = bp - 1;
        }
        return profit;
    }
private:
    int findSell(const vector<int> &prices, int pos) {
        while (pos > 0 && prices[pos] <= prices[pos - 1])
            pos--;
        return pos;
    }
    int findBuy(const vector<int> &prices, int pos) {
        while (pos > 0 && prices[pos] > prices[pos - 1])
            pos--;
        return pos;
    }
};