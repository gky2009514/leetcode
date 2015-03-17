class Solution {
public:
    string longestPalindrome(string s) {
        int N = (int)s.length();
        int M = N * 2 + 1;
        string check(M, '*');
        for (int i = 0; i < N; i++)
            check[(i << 1) | 1] = s[i];
        int *dp = new int[M];
        dp[0] = 1, dp[1] = 3;
        int nc = 1, nr = 2;
        int pos = 0, ma = 3;
        for (int i = 2; i < M; i++) {
            int neg = (nc << 1) - i;
            if (neg >= 0)
                dp[i] = min(dp[neg], dp[nc] - 2 * (i - nc));
            else
                dp[i] = 1;
            int j = i - (dp[i] + 1) / 2;
            int k = i + (dp[i] + 1) / 2;
            while (j >= 0 && k < M && check[j] == check[k]) {
                dp[i] += 2;
                j--, k++;
            }
            if (i + (dp[i] >> 1) > nr) {
                nr = i + (dp[i] >> 1);
                nc = i;
            }
            if (dp[i] > ma) {
                ma = dp[i];
                pos = (i - (dp[i] >> 1)) >> 1;
            }
        }
        delete dp;
        return s.substr(pos, ma >> 1);
    }
};