class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        N = (int)grid.size();
        M = (int)grid[0].size();
        for (int i = 1; i < N; i++)
            grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < M; i++)
            grid[0][i] += grid[0][i - 1];
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++)
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
        }
        return grid[N - 1][M - 1];
    }
private:
    int N, M;
};