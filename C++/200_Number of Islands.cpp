class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        N = (int)grid.size();
        M = (int)grid[0].size();
        vector<vector<bool> > flag(N, vector<bool>(M, false));
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '1' && !flag[i][j]) {
                    res++;
                    dfs(i, j, grid, flag);
                }
            }
        }
        return res;
    }
private:
    int N, M;
    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &flag) {
        if (x < 0 || x >= N || y < 0 || y >= M)
            return;
        if (grid[x][y] == '1' && !flag[x][y]) {
            flag[x][y] = true;
            dfs(x - 1, y, grid, flag);
            dfs(x + 1, y, grid, flag);
            dfs(x, y - 1, grid, flag);
            dfs(x, y + 1, grid, flag);
        }
    }
};