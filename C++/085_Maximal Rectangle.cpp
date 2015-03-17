class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int N = (int)matrix.size();
        int M = (int)matrix[0].size();
        vector<vector<int> > sum(N + 1, vector<int>(M, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++)
                sum[i][j] = sum[i - 1][j] + matrix[i - 1][j] - '0';
        }
        int res = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                int ma = 0, tmp = 0;
                for (int k = 0; k < M; k++) {
                    if (sum[j][k] - sum[i - 1][k] < j - i + 1)
                        tmp = 0;
                    else
                        tmp += 1;
                    ma = max(ma, tmp);
                }
                res = max(res, ma * (j - i + 1));
            }
        }
        return res;
    }
};