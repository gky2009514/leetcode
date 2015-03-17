class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        N = (int)prices.size();
        if (N <= 1 || k == 0)
            return 0;
        if(k > (N >> 1))
            return maxBuy(prices);
        vector<int> global(k + 1, 0);
        vector<int> local(k + 1, 0);
        for (int i = 1; i < N; i++) {
            int dif = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; j--) {
                local[j] = max(local[j] + dif, global[j - 1] + max(dif, 0));
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }
private:
    int N;
    int maxBuy(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < N; i++) {
            int dif = prices[i] - prices[i - 1];
            res += dif > 0 ? dif : 0;
        }
        return res;
    }  
};