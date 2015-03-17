class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if (n == 0 || n == 2 || n == 3)
            return res;
        col = vector<bool>(n, false);
        ltor = vector<bool>(n << 1, false);
        rtol = vector<bool>(n << 1, false);
        board = vector<string>(n, string(n, '.'));
        this->n = n;
        backtrack(res, 0);
        return res;
    }
private:
    int n;
    vector<bool> col, ltor, rtol;
    vector<string> board;
    void backtrack(vector<vector<string> > &res, int x) {
        if (x >= n) {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !ltor[x + i] && !rtol[n - 1 - i + x]) {
                col[i] = ltor[x + i] = rtol[n - 1 - i + x] = true;
                board[x][i] = 'Q';
                backtrack(res, x + 1);
                board[x][i] = '.';
                col[i] = ltor[x + i] = rtol[n - 1 - i + x] = false;
            }
        }
    }
};