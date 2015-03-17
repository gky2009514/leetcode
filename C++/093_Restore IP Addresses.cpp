class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        N = (int)s.length();
        char *str = new char[N + 5];
        vector<string> res;
        str[N + 3] = '\0';
        dfs(str, res, 0, 0);
        delete str;
        return res;
    }
private:
    string s;
    int N;
    bool inRange(int st, int ed) {
        if (ed < st || ed - st >= 3)
            return false;
        if (ed - st > 0 && s[st] == '0')
            return false;
        int num = 0;
        for (int i = st; i <= ed; i++)
            num = num * 10 + (s[i] - '0');
        return num <= 255;
    }
    void dfs(char *str, vector<string> &res, int pos, int num) {
        if (num == 3) {
            if (inRange(pos, N - 1)) {
                for (int i = pos; i < N; i++)
                    str[i + num] = s[i];
                res.push_back(string(str));
            }
            return;
        }
        for (int i = pos; i <= pos + 2 && i < N; i++) {
            if (inRange(pos, i)) {
                for (int j = pos; j <= i; j++)
                    str[j + num] = s[j];
                str[i + num + 1] = '.';
                dfs(str, res, i + 1, num + 1);
            }
        }
    }
};