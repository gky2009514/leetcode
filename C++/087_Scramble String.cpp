class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        N = (int)s1.length();
        if (N == 0)
            return true;
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        for (int i = 0; i < N; i++) {
            if (t1[i] != t2[i])
                return false;
        }
        vector<vector<vector<bool>>> scram(N, vector<vector<bool>>(N, vector<bool>(N + 1, false)));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (s1[i] == s2[j])
                    scram[i][j][1] = true;
            }
        }
        for (int k = 2; k <= N; k++) {
            for (int i = 0; i <= N - k; i++) {
                for (int j = 0; j <= N - k; j++) {
                    t1 = s1.substr(i, k);
                    t2 = s2.substr(j, k);
                    if (same(t1, t2))
                        scram[i][j][k] = true;
                    else {
                        for (int l = 1; l < k; l++) {
                            if ((scram[i][j][l] && scram[i + l][j + l][k - l]) ||
                                (scram[i][j + k - l][l] && scram[i + l][j][k - l])) {
                                scram[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return scram[0][0][N];
    }
private:
    int N;
    bool same(const string &s1, const string &s2) {
        int len = (int)s1.length();
        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
};