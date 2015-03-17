class Solution {
public:
    int sqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        long long num = x;
        double res = 1, pre = 0;
        while (fabs(res - pre) > EPS) {
            pre = res;
            res = (res + num / res) / 2;
        }
        return (int)res;
    }
private:
    const double EPS = 0.0001;
};