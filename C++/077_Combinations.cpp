class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<vector<int> > res;
        if (k == 0) {
            res.push_back(vector<int>());
            return res;
        }
        v.clear();
        dfs(0, 1, res);
        return res;
    }
private:
    int n, k;
    vector<int> v;
    void dfs(int pos, int num, vector<vector<int> > &res) {
        if (n - num + 1 < k - pos)
            return;
        if (pos >= k) {
            res.push_back(v);
            return;
        }
        v.push_back(num);
        dfs(pos + 1, num + 1, res);
        v.pop_back();
        dfs(pos, num + 1, res);
    }
};