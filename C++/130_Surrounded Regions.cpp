class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0)
            return;
        n = (int)board.size();
        m = (int)board[0].size();
        for (int i = 0; i < m; i++) {
            bfs(0, i, board);
            bfs(n - 1, i, board);
        }
        for (int i = 0; i < n; i++) {
            bfs(i, 0, board);
            bfs(i, m - 1, board);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                board[i][j] = board[i][j] == 'Y' ? 'O' : 'X';
        }
    }
private:
    int n, m;
    int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void bfs(int x, int y, vector<vector<char>> &board) {
        if (board[x][y] != 'O')
            return;
        board[x][y] = 'Y';
        queue<int> qx, qy;
        while (!qx.empty())
            qx.pop();
        while (!qy.empty())
            qy.pop();
        qx.push(x);
        qy.push(y);
        while (!qx.empty()) {
            int x = qx.front();
            qx.pop();
            int y = qy.front();
            qy.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + direct[i][0];
                int ny = y + direct[i][1];
                if (visit(nx, ny, board)) {
                    board[nx][ny] = 'Y';
                    qx.push(nx);
                    qy.push(ny);
                }
            }
        }
    }
    bool visit(int x, int y, vector<vector<char>> &board) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O')
            return false;
        return true;
    }
};