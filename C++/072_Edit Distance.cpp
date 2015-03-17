class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int)word1.length();
        int m = (int)word2.length();
        if (0 == n)
            return m;
        if (0 == m)
            return n;
        int **dp = new int*[n + 1];
        int i, j;
        for (i = 0; i <= n; i++) {
            dp[i] = new int[m + 1];
            dp[i][0] = i;
        }
        for (i = 1; i <= m; i++)
            dp[0][i] = i;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                int mi;
                if (word1[i - 1] == word2[j - 1])
                    mi = dp[i - 1][j - 1];
                else
                    mi = dp[i - 1][j - 1] + 1;
                dp[i][j] = min(mi, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }
        return dp[n][m];
    }
};