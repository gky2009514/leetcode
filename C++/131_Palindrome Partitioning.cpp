class Solution {
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        N = (int)s.length();
        res.clear();
        isPal.clear();
        vector<bool> init;
        for (int i = 0; i < N; i++)
            init.push_back(false);
        for (int i = 0; i < N; i++)
            isPal.push_back(init);
        for (int i = 0; i < N; i++)
            isPal[i][i] = true;
        for (int i = 0; i < N - 1; i++) {
            if (s[i] == s[i + 1])
                isPal[i][i + 1] = true;
        }
        for (int i = 2; i < N; i++) {
            for (int j = 0; j < N - i; j++) {
                if (s[j] == s[j + i] && isPal[j + 1][j + i - 1])
                    isPal[j][j + i] = true;
            }
        }
        vector<string> v;
        dfs(0, v);
        return res;
    }
private:
    int N;
    vector<vector<string>> res;
    vector<vector<bool>> isPal;
    string s;
    void dfs(int pos, vector<string> &v) {
        if (pos >= N) {
            res.push_back(v);
            return;
        }
        for (int i = pos; i < N; i++) {
            if (isPal[pos][i]) {
                v.push_back(s.substr(pos, i - pos + 1));
                dfs(i + 1, v);
                v.pop_back();
            }
        }
    }
};