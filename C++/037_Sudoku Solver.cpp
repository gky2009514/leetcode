class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        pos.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.')
                    pos.push_back(i * N + j);
            }
        }
        L = (int)pos.size();
        backtrack(board, 0);
    }
private:
    const int N = 9;
    const int M = 3;
    int L;
    vector<int> pos;
    bool checkRow(vector<vector<char> > &board, int row, char digit) {
        for (int i = 0; i < N; i++) {
            if (board[row][i] == digit)
                return false;
        }
        return true;
    }
    bool checkCol(vector<vector<char> > &board, int col, char digit) {
        for (int i = 0; i < N; i++) {
            if (board[i][col] == digit)
                return false;
        }
        return true;
    }
    bool checkSqua(vector<vector<char> > &board, int row, int col, char digit) {
        for (int i = row; i < row + M; i++) {
            for (int j = col; j < col + M; j++) {
                if (board[i][j] == digit)
                    return false;
            }
        }
        return true;
    }
    bool backtrack(vector<vector<char> > &board, int x) {
        if (x >= L)
            return true;
        int row = pos[x] / N;
        int col = pos[x] % N;
        for (int i = 0; i < N; i++) {
            char c = '0' + 1 + i;
            if (checkRow(board, row, c) && checkCol(board, col, c)) {
                int nr = (row / M) * M, nc = (col / M) * M;
                if (checkSqua(board, nr, nc, c)) {
                    board[row][col] = c;
                    if (backtrack(board, x + 1))
                        return true;
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
};