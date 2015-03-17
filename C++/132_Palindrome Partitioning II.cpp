class Solution {
public:
    int minCut(string s) {
        N = (int)s.length();
        if (N == 0 || N == 1)
            return 0;
        if (N == 2)
            return s[0] == s[1] ? 0 : 1;
        bool **isPal = new bool *[N];
        for (int i = 0; i < N; i++)
            isPal[i] = new bool[N];
        for (int i = 0; i < N - 1; i++) {
            isPal[i][i] = true;
            isPal[i][i + 1] = s[i] == s[i + 1];
        }
        isPal[N - 1][N - 1] = true;
        for (int j = 2; j < N; j++) {
            for (int i = 0; i < N - j; i++)
                isPal[i][i + j] = s[i] == s[i + j] && isPal[i + 1][i + j - 1];
        }
        if (isPal[0][N - 1])
            return 0;
        int *dp = new int[N];
        dp[0] = 0;
        for (int i = 1; i < N; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;
                continue;
            }
            dp[i] = INT_MAX;
            for (int j = i; j > 0; j--) {
                if (isPal[j][i])
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        int res = dp[N - 1];
        for (int i = 0; i < N; i++)
            delete[] isPal[i];
        delete[] dp;
        return res;
    }
private:
    int N;
};