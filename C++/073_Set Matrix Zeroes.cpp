class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        N = (int)matrix.size();
        M = (int)matrix[0].size();
        bool rflag[N], cflag[M];
        for (int i = 0; i < N; i++)
            rflag[i] = false;
        for (int i = 0; i < M; i++)
            cflag[i] = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 0)
                    rflag[i] = cflag[j] = true;
            }
        }
        for (int i = 0; i < N; i++) {
            if (rflag[i]) {
                for (int j = 0; j < M; j++)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 0; j < M; j++) {
            if (cflag[j]) {
                for (int i = 0; i < N; i++)
                    matrix[i][j] = 0;
            }
        }
    }
private:
    int N, M;
};