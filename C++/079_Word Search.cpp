class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0 || board[0].size() == 0 || word.length() == 0)
            return false;
        N = (int)board.size();
        M = (int)board[0].size();
        L = (int)word.length();
        vector<vector<bool> > visit;
        vector<bool> v;
        for (int i = 0; i < M; i++)
            v.push_back(false);
        for (int i = 0; i < N; i++)
            visit.push_back(v);
        this->word = word;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == word[0] && dfs(board, visit, i, j, 1))
                    return true;
            }
        }
        return false;
    }
private:
    string word;
    int N, M, L;
    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &visit, int x, int y, int pos) {
        if (pos >= L)
            return true;
        visit[x][y] = true;
        if (x - 1 >= 0 && board[x - 1][y] == word[pos] && !visit[x - 1][y] && dfs(board, visit, x - 1, y, pos + 1))
            return true;
        if (x + 1 < N && board[x + 1][y] == word[pos] && !visit[x + 1][y] && dfs(board, visit, x + 1, y, pos + 1))
            return true;
        if (y - 1 >= 0 && board[x][y - 1] == word[pos] && !visit[x][y - 1] && dfs(board, visit, x, y - 1, pos + 1))
            return true;
        if (y + 1 < M && board[x][y + 1] == word[pos] && !visit[x][y + 1] && dfs(board, visit, x, y + 1, pos + 1))
            return true;
        visit[x][y] = false;
        return false;
    }
};