class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int N = (int)triangle.size();
        if (N == 0)
            return 0;
        int *dp = new int[N + 1];
        for (int i = 0; i < N; i++)
            dp[i] = 0;
        dp[0] = triangle[0][0];
        for (int i = 1; i < N; i++) {
            int pre = dp[0];
            dp[0] += triangle[i][0];
            for (int j = 1; j < i; j++) {
                int tmp = dp[j];
                dp[j] = triangle[i][j] + min(pre, dp[j]);
                pre = tmp;
            }
            dp[i] = pre + triangle[i][i];
        }
        int mi = dp[0];
        for (int i = 1; i < N; i++)
            mi = min(mi, dp[i]);
        delete dp;
        return mi;
    }
};