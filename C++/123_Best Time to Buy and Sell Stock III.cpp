class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        N = (int)prices.size();
        vector<int> left(N, 0), right(N, 0);
        int mi = prices[0];
        for (int i = 1; i < N; i++) {
            left[i] = max(left[i - 1], prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        int ma = prices[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], ma - prices[i]);
            ma = max(ma, prices[i]);
        }
        int res = max(right[0], left[N - 1]);
        for (int i = 0; i < N - 1; i++)
            res = max(res, left[i] + right[i + 1]);
        return res;
    }
private:
    int N;
};