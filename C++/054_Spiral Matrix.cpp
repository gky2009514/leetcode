class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        N = (int)matrix.size();
        M = (int)matrix[0].size();
        int top = 0, left = 0;
        int down = N - 1, right = M - 1;
        while (top <= down && left <= right) {
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            if (top == down)
                break;
            for (int i = top + 1; i <= down; i++)
                res.push_back(matrix[i][right]);
            if (left == right)
                break;
            for (int i = right - 1; i >= left; i--)
                res.push_back(matrix[down][i]);
            for (int i = down - 1; i > top; i--)
                res.push_back(matrix[i][left]);
            top++, down--;
            left++, right--;
        }
        return res;
    }
private:
    int N, M;
};