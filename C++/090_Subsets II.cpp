class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        res.push_back(vector<int>());
        sort(S.begin(), S.end());
        int N = (int)S.size(), i = 0;
        while (i < N) {
            int j = i + 1;
            while (j < N && S[j] == S[i])
                j++;
            pushSame(res, S[i], j - i);
            i = j;
        }
        return res;
    }
private:
    void pushSame(vector<vector<int> > &res, int x, int num) {
        int N = (int)res.size();
        vector<int> v;
        for (int i = 0; i < num; i++) {
            v.push_back(x);
            res.push_back(v);
        }
        for (int i = 1; i < N; i++) {
            for (int j = N; j < N + num; j++) {
                vector<int> tmp;
                tmp.insert(tmp.end(), res[i].begin(), res[i].end());
                tmp.insert(tmp.end(), res[j].begin(), res[j].end());
                res.push_back(tmp);
            }
        }
    }
};