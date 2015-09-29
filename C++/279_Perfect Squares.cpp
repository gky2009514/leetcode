class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 10000);
        int up = (int)sqrt(n);
        for (int i = 1; i <= n; i++) {
            int k = (int)sqrt(i);
            if (k * k == i)
                dp[i] = 1;
            for (int j = 1; j <= up; j++) {
                k = i + j * j;
                if (k > n)
                    break;
                dp[k] = min(dp[k], dp[i] + 1);
            }
        }
        return dp[n];
    }
};