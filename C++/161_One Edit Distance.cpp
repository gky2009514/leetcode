class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        N = (int)s.length();
        M = (int)t.length();
        if (abs(N - M) > 1)
            return false;
        this->s = s;
        this->t = t;
        return editDist(0, 0, 0);
    }
private:
    int N, M;
    string s, t;
    bool editDist(int x, int y, int num) {
        if (num > 1)
            return false;
        if (x >= N)
            return (M - y) + num == 1;
        if (y >= M)
            return (N - x) + num == 1;
        if (s[x] == t[y])
            return editDist(x + 1, y + 1, num);
        else {
            if (editDist(x + 1, y + 1, num + 1))
                return true;
            if (editDist(x, y + 1, num + 1))
                return true;
            if (editDist(x + 1, y, num + 1))
                return true;
            return false;
        }
    }
};