class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (m == 1 || n == 1)
            return 1;
        int steps = m + n - 2;
        vector<int> v;
        v.push_back(1);
        for (int i = 1; i <= steps; i++) {
            int pre = v[0];
            for (int j = 1; j < i; j++) {
                int tmp = v[j];
                v[j] += pre;
                pre = tmp;
            }
            v.push_back(1);
        }
        return v[m - 1];
    }
};