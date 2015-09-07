class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        res.clear();
        if (n <= 1)
            return res;
        now.clear();
        dfs(1, n);
        res.pop_back();
        return res;
    }

private:
    vector<int> now;
    vector<vector<int> > res;
    void dfs(int x, int l) {
        if (l == 1) {
            res.push_back(now);
            return;
        }
        for (int i = x + 1; i <= l; i++) {
            if (l % i == 0) {
                int m = l;
                while (m % i == 0) {
                    now.push_back(i);
                    m /= i;
                    dfs(i, m);
                }
                while (m != l) {
                    m *= i;
                    now.pop_back();
                }
            }
        }
    }
};