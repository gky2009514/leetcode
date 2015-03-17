class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0)
            return 0;
        N = (int)s.length();
        v = vector<int>(N, -1);
        return dfs(0, s);
    }
private:
    int N;
    vector<int> v;
    int dfs(int pos, string &s) {
        if (pos >= N)
            return 1;
        if (v[pos] != -1)
            return v[pos];
        if (s[pos] == '0')
            return 0;
        v[pos] = dfs(pos + 1, s);
        if (pos < N - 1) {
            int tmp = (s[pos] - '0') * 10 + s[pos + 1] - '0';
            if (tmp <= 26)
                v[pos] += dfs(pos + 2, s);
        }
        return v[pos];
    }
};