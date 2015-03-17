class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        N = (int)s1.length();
        M = (int)s2.length();
        L = (int)s3.length();
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        if (N + M != L)
            return false;
        dp = vector<vector<int> >(N + 1, vector<int>(M + 1, -1));
        return interleave(0, 0, 0) == 1;
    }
private:
    int N, M, L;
    string s1, s2, s3;
    vector<vector<int> > dp;
    int interleave(int l, int r, int pos) {
        if (pos >= L)
            return 1;
        if (dp[l][r] != -1)
            return dp[l][r];
        if (s1[l] == s3[pos]) {
            if (interleave(l + 1, r, pos + 1) == 1)
                dp[l][r] = 1;
        }
        if (dp[l][r] == -1 && s2[r] == s3[pos]) {
            if (interleave(l, r + 1, pos + 1) == 1)
                dp[l][r] = 1;
        }
        dp[l][r] = dp[l][r] == -1 ? 0 : dp[l][r];
        return dp[l][r];
    }
};