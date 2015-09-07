class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n <= 1)
            return true;
        int m = (int)edges.size();
        if (m != n - 1)
            return false;
        vector<int> father(n, 0);
        for (int i = 0; i < n; i++)
            father[i] = i;
        for (int i = 0; i < m; i++) {
            int fa = findFather(father, edges[i].first);
            int fb = findFather(father, edges[i].second);
            if (fa == fb)
                return false;
            father[fa] = fb;
        }
        return true;
    }

private:
    int findFather(vector<int> &f, int x) {
        if (f[x] != x)
            f[x] = findFather(f, f[x]);
        return f[x];
    }
};