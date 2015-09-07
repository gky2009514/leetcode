class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        res.clear();
        if (n <= 0)
            return res;
        s = string(n, '0');
        dfs(0, n - 1);
        return res;
    }

private:
    const static int N = 3;
    char digits[N] = {'0', '1', '8'};
    string s;
    vector<string> res;
    void dfs(int l, int r) {
        if (l > r) {
            res.push_back(s);
            return;
        }
        if (l == r) {
            for (int i = 0; i < N; i++) {
                s[l] = digits[i];
                res.push_back(s);
            }
            return;
        }
        s[l] = '6', s[r] = '9';
        dfs(l + 1, r - 1);
        s[l] = '9', s[r] = '6';
        dfs(l + 1, r - 1);
        int i = l > 0 ? 0 : 1;
        for ( ; i < N; i++) {
            s[l] = s[r] = digits[i];
            dfs(l + 1, r - 1);
        }
    }
};