class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        N = (int)num.size();
        v.clear();
        dfs(res, num, 0, target);
        return res;
    }
private:
    int N;
    vector<int> v;
    void dfs(vector<vector<int> > &res, vector<int> &num, int pos, int left) {
        if (pos >= N || left < num[pos]) {
            if (left == 0)
                res.push_back(v);
            return;
        }
        if (pos > 0 && num[pos] == num[pos - 1]) {
            dfs(res, num, pos + 1, left);
            return;
        }
        int len = pos + 1;
        while (len < N && num[len] == num[pos])
            len++;
        int i = pos;
        do {
            dfs(res, num, pos + 1, left);
            v.push_back(num[pos]);
            i++;
            left -= num[pos];
        } while(i <= len);
        for (i = pos; i <= len; i++)
            v.pop_back();
    }
};