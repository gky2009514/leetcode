class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        N = static_cast<int>(matrix.size());
        if (N == 0)
            return 0;
        M = static_cast<int>(matrix[0].size());
        if (M == 0)
            return 0;
        vector<vector<long long> > area(N + 1, vector<long long>(M + 1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                area[i + 1][j + 1] = area[i][j + 1] + area[i + 1][j] - area[i][j];
                area[i + 1][j + 1] += matrix[i][j] == '1';
            }
        }
        int res = 0, up = 0;
        for (int i = 0; i < N - up; i++) {
            for (int j = 0; j < M - up; j++) {
                for (int k = 0; i + k < N && j + k < M; k++) {
                    long long ar = area[i + k + 1][j + k + 1] - area[i][j + k + 1] -
                        area[i + k + 1][j] + area[i][j];
                    if (ar == (k + 1) * (k + 1)) {
                        res = max(res, (int)ar);
                        up = max(up, k);
                    }
                    else
                        break;
                }
            }
        }
        return res;
    }

private:
    int N, M;
};