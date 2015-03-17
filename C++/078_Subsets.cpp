class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        res.push_back(vector<int>());
        N = (int)S.size();
        sort(S.begin(), S.end());
        vector<int> v;
        for (int i = 0; i < N; ) {
            int j = i + 1;
            while (j < N && S[j] == S[i])
                j++;
            v.clear();
            int M = (int)res.size();
            for (int k = 0; k < j - i; k++) {
                v.push_back(S[i]);
                res.push_back(v);
            }
            vector<int> tmp;
            for (int k = 1; k < M; k++) {
                for (int l = M; l < M + j - i; l++) {
                    tmp.clear();
                    tmp.insert(tmp.end(), res[k].begin(), res[k].end());
                    tmp.insert(tmp.end(), res[l].begin(), res[l].end());
                    res.push_back(tmp);
                }
            }
            i = j;
        }
        return res;
    }
private:
    int N;
};