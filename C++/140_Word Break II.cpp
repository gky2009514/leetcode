class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        N = (int)s.length();
        if (N == 0)
            return res;
        this->s = s;
        word = "";
        dp = vector<bool>(N, false);
        dp[N] = true;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = i + 1; j <= N; j++) {
                string t = s.substr(i, j - i);
                if (dict.find(t) != dict.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        dfs(0, res, dict);
        return res;
    }
private:
    int N;
    string s, word;
    vector<bool> dp;
    void dfs(int pos, vector<string> &res, unordered_set<string> &dict) {
        if (pos >= N) {
            res.push_back(word);
            return;
        }
        if (!dp[pos])
            return;
        for (int i = pos + 1; i <= N; i++) {
            string t = s.substr(pos, i - pos);
            if (dict.find(t) != dict.end()) {
                int len = (int)word.length();
                if (len == 0) {
                    word.append(t);
                    dfs(i, res, dict);
                    word = "";
                }
                else {
                    word.append(1, ' ');
                    word.append(t);
                    dfs(i, res, dict);
                    word = word.substr(0, len);
                }
            }
        }
    }
};