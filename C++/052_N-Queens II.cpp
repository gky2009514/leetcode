class Solution {
public:
    int totalNQueens(int n) {
        if (n == 0 || n == 2 || n == 3)
            return 0;
        if (n == 1)
            return 1;
        this->n = n;
        col = vector<bool>(n, false);
        ltor = vector<bool>(n << 1, false);
        rtol = vector<bool>(n << 1, false);
        board = vector<string>(n, string(n, '.'));
        backtrack(0);
        return num;
    }
private:
    int n, num;
    vector<bool> col, ltor, rtol;
    vector<string> board;
    void backtrack(int x) {
        if (x >= n) {
            num++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !ltor[x + i] && !rtol[n - 1 - i + x]) {
                col[i] = ltor[x + i] = rtol[n - 1 - i + x] = true;
                board[x][i] = 'Q';
                backtrack(x + 1);
                board[x][i] = '.';
                col[i] = ltor[x + i] = rtol[n - 1 - i + x] = false;
            }
        }
    }
};