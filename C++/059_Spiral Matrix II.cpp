class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(0);
        for (int i = 0; i < n; i++)
            res.push_back(v);
        int up = 0, left = 0;
        int down = n - 1, right = n - 1;
        int num = 1;
        while (up <= down) {
            for (int i = left; i <= right; i++)
                res[up][i] = num++;
            for (int i = up + 1; i <= down; i++)
                res[i][right] = num++;
            for (int i = right - 1; i >= left; i--)
                res[down][i] = num++;
            for (int i = down - 1; i > up; i--)
                res[i][left] = num++;
            up++, down--;
            left++, right--;
        }
        return res;
    }
};