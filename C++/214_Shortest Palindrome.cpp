class Solution {
public:
    string shortestPalindrome(string s) {
        int len = (int)s.length();
        if (len == 0 || len == 1)
            return s;
        char *str = new char[(len << 1) + 5];
        int i, j, k, mj, mc, ma, rc;
        for (i = j = 0; i < len; i++) {
            str[j++] = '*';
            str[j++] = s[i];
        }
        str[j++] = '*';
        len = j;
        int *dp = new int[len + 5];
        dp[0] = 1, dp[1] = 3, rc = mc = 1, mj = 2;
        for (i = 2, ma = 3; i < len; i++) {
            dp[i] = min(dp[(mc << 1) - i], dp[mc] - 2 * (i - mc));
            dp[i] = 0 >= dp[i] ? 1 : dp[i];
            j = i - (dp[i] + 1) / 2;
            k = i + (dp[i] + 1) / 2;
            while (0 <= j && k < len && str[j] == str[k]) {
                dp[i] += 2;
                j--, k++;
            }
            if (j < 0)
                rc = i;
            if (i + (dp[i] >> 1) > mj) {
                mj = i + (dp[i] >> 1);
                mc = i;
            }
        }
        string ct = s.substr(rc, s.length() - rc);
        reverse(ct.begin(), ct.end());
        return ct + s;
    }
};