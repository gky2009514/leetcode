class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        if (k == 0)
            return res;
        this->k = k;
        this->n = n;
        dfs(0, 0, 0);
        return res;
    }

private:
    int k, n;
    vector<int> now;
    vector<vector<int> > res;
    void dfs(int pre, int p, int sum) {
        if (sum > n)
            return;
        if (p == k - 1) {
            if (n - sum > pre && n - sum <= 9) {
                now.push_back(n - sum);
                res.push_back(now);
                now.pop_back();
            }
            return;
        }
        for (int i = pre + 1; i <= 9; i++) {
            now.push_back(i);
            dfs(i, p + 1, sum + i);
            now.pop_back();
        }
    }
};