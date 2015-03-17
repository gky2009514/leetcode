class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        long long tmp = x, res = 0;
        if (x < 0) {
            tmp = -(long long)x;
            neg = true;
        }
        while (tmp) {
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        if (neg) {
            if (-res < INT_MIN)
                return 0;
            return (int)-res;
        }
        else {
            if (res > INT_MAX)
                return 0;
            return (int)res;
        }
    }
};