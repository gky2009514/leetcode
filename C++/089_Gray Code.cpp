class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n >= 0) {
            res.push_back(0);
            for (int i = 1; i <= n; i++) {
                vector<int> tmp = res;
                res.clear();
                for (int j = 0; j < tmp.size(); j++)
                    res.push_back(setZero(tmp[j], i - 1));
                for (int j = (int)tmp.size() - 1; j >= 0; j--)
                    res.push_back(setOne(tmp[j], i - 1));
            }
        }
        return res;
    }
private:
    int setOne(int x, int pos) {
        return x | (1 << pos);
    }
    int setZero(int x, int pos) {
        return x & ~(1 << pos);
    }
};