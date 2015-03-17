class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        res.clear();
        if (numRows >= 1) {
            vector<int> v[2];
            v[0].clear();
            v[0].push_back(1);
            res.push_back(v[0]);
            for (int i = 2; i <= numRows; i++) {
                if (!(i & 1)) {
                    v[1].clear();
                    v[1].push_back(1);
                    for (int j = 0; j < v[0].size() - 1; j++)
                        v[1].push_back(v[0][j] + v[0][j + 1]);
                    v[1].push_back(1);
                    res.push_back(v[1]);
                }
                else {
                    v[0].clear();
                    v[0].push_back(1);
                    for (int j = 0; j < v[1].size() - 1; j++)
                        v[0].push_back(v[1][j] + v[1][j + 1]);
                    v[0].push_back(1);
                    res.push_back(v[0]);
                }
            }
        }
        return res;
    }
};