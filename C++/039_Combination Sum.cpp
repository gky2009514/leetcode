class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int>::iterator pos = unique(candidates.begin(), candidates.end());
        candidates.erase(pos, candidates.end());
        N = (int)candidates.size();
        v.clear();
        dfs(res, candidates, 0, target);
        return res;
    }
private:
    int N;
    vector<int> v;
    void dfs(vector<vector<int> > &res, vector<int> &candi, int pos, int left) {
        if (pos >= N || left < candi[pos]) {
            if (left == 0)
                res.push_back(v);
            return;
        }
        int num = left / candi[pos];
        int i = 0;
        do {
            dfs(res, candi, pos + 1, left);
            v.push_back(candi[pos]);
            i++;
            left -= candi[pos];
        } while(i <= num);
        for (i = 0; i <= num; i++)
            v.pop_back();
    }
};