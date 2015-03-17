class Solution {
public:
    int maxPoints(vector<Point> &points) {
        N = (int)points.size();
        if (N <= 2)
            return N;
        int res = 0;
        for (int i = 0; i < N; i++) {
            mp.clear();
            int dup = 1;
            for (int j = 0; j < N; j++) {
                if (j == i)
                    continue;
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    dup++;
                    continue;
                }
                double k = points[i].x == points[j].x ? LONG_LONG_MAX : (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                mp[k]++;
            }
            res = max(res, dup);
            for (auto it = mp.begin(); it != mp.end(); it++)
                res = max(res, it->second + dup);
        }
        return res;
    }
private:
    int N;
    map<double, int> mp;
};