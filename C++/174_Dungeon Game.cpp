class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0)
            return 1;
        N = (int)dungeon.size();
        M = (int)dungeon[0].size();
        int **dp = new int *[N];
        for (int i = 0; i < N; i++)
            dp[i] = new int[M];
        dp[N - 1][M - 1] = max(0 - dungeon[N - 1][M - 1], 0);
        for (int i = N - 2; i >= 0; i--)
            dp[i][M - 1] = max(dp[i + 1][M - 1] - dungeon[i][M - 1], 0);
        for (int i = M - 2; i >= 0; i--)
            dp[N - 1][i] = max(dp[N - 1][i + 1] - dungeon[N - 1][i], 0);
        for (int i = N - 2; i >= 0; i--) {
            for (int j = M - 2; j >= 0; j--)
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 0);
        }
        int res = dp[0][0] + 1;
        for (int i = 0; i < N; i++)
            delete[] dp[i];
        delete[] dp;
        return res;
    }
private:
    int N, M;
};