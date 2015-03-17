class Solution {
public:
    double pow(double x, int n) {
        if (n == 0 || x == 1.0)
            return 1;
        bool flag = n < 0;
        long long p = abs((long long)n);
        long double radix = x, res = 1.0;
        while (p) {
            if (p & 1)
                res *= radix;
            radix = radix * radix;
            p >>= 1;
        }
        return flag ? 1.0 / res : res;
    }
};