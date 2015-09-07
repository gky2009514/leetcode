class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = (int)costs.size();
        if (n == 0)
            return 0;
        int m = (int)costs[0].size();
        if (m == 0)
            return 0;
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
            dp[0][i] = costs[0][i];
        for (int i = 1; i < n; i++) {
            int mt = INT_MAX, k = -1;
            for (int j = 0; j < m; j++) {
                if (dp[i - 1][j] < mt)
                    mt = dp[i - 1][j], k = j;
            }
            mt = INT_MAX;
            for (int j = 0; j < m; j++) {
                if (j == k)
                    continue;
                mt = min(mt, dp[i - 1][j]);
                dp[i][j] = dp[i - 1][k] + costs[i][j];
            }
            dp[i][k] = mt + costs[i][k];
        }
        int mi = dp[n - 1][0];
        for (int i = 1; i < m; i++)
            mi = min(mi, dp[n - 1][i]);
        return mi;
    }
};