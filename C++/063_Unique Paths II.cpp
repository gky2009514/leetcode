class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        N = (int)obstacleGrid.size();
        M = (int)obstacleGrid[0].size();
        obstacleGrid[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 1; i < N; i++) {
            if (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0])
                obstacleGrid[i][0] = 1;
            else
                obstacleGrid[i][0] = 0;
        }
        for (int i = 1; i < M; i++) {
            if (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1])
                obstacleGrid[0][i] = 1;
            else
                obstacleGrid[0][i] = 0;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                else
                    obstacleGrid[i][j] = 0;
            }
        }
        return obstacleGrid[N - 1][M - 1];
    }
private:
    int N, M;
};