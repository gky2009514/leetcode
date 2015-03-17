class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.clear();
        res.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 0; j < res.size() - 1; j++)
                res[j] += res[j + 1];
            reverse(res.begin(), res.end());
            res.push_back(1);
        }
        return res;
    }
};