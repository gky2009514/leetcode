class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        N = (int)matrix.size();
        M = (int)matrix[0].size();
        int i = 0, j = N - 1;
        while (i < j) {
            for (int k = 0; k < M; k++) {
                int tmp = matrix[i][k];
                matrix[i][k] = matrix[j][k];
                matrix[j][k] = tmp;
            }
            i++, j--;
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
private:
    int N, M;
};