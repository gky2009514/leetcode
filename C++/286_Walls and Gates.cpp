class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = static_cast<int>(rooms.size());
        if (n == 0)
            return;
        int m = static_cast<int>(rooms[0].size());
        if (m == 0)
            return;
        queue<point> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0)
                    q.push(point(i, j, 0));
            }
        }
        while (!q.empty()) {
            point ft = q.front();
            q.pop();
            if (ft.step > rooms[ft.x][ft.y])
                continue;
            for (int i = 0; i < N; i++) {
                int nx = ft.x + direct[i][0];
                int ny = ft.y + direct[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                    rooms[nx][ny] == -1 || rooms[nx][ny] == 0)
                    continue;
                if (ft.step + 1 < rooms[nx][ny]) {
                    rooms[nx][ny] = ft.step + 1;
                    q.push(point(nx, ny, ft.step + 1));
                }
            }
        }
    }

private:
    struct point {
        int x, y, step;
        point(int x, int y, int s): x(x), y(y), step(s) {}
    };
    static const int N = 4;
    int direct[N][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};