class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); i++) {
            if (!isRowValid(board, i))
                return false;
        }
        for (int i = 0; i < board[0].size(); i++) {
            if (!isColValid(board, i))
                return false;
        }
        for (int i = 0; i < board.size(); i += M) {
            for (int j = 0; j < board[i].size(); j += M)
                if (!isMatValid(board, i, j))
                    return false;
        }
        return true;
    }
private:
    const int N = 10;
    const int M = 3;
    bool isRowValid(vector<vector<char> > &board, int row) {
        bool flag[N];
        memset(flag, false, sizeof(flag));
        for (int i = 0; i < board[row].size(); i++) {
            if (board[row][i] == '.')
                continue;
            if (flag[board[row][i] - '0'])
                return false;
            flag[board[row][i] - '0'] = true;
        }
        return true;
    }
    bool isColValid(vector<vector<char> > &board, int col) {
        bool flag[N];
        memset(flag, false, sizeof(flag));
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == '.')
                continue;
            if (flag[board[i][col] - '0'])
                return false;
            flag[board[i][col] - '0'] = true;
        }
        return true;
    }
    bool isMatValid(vector<vector<char> > &board, int x, int y) {
        bool flag[N];
        memset(flag, false, sizeof(flag));
        for (int i = x; i < x + M; i++) {
            for (int j = y; j < y + M; j++) {
                if (board[i][j] == '.')
                    continue;
                if (flag[board[i][j] - '0'])
                    return false;
                flag[board[i][j] - '0'] = true;
            }
        }
        return true;
    }
};