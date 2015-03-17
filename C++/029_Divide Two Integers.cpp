class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0 || divisor == 1)
            return dividend;
        if (divisor == -1)
            return dividend == INT_MIN ? INT_MAX : -dividend;
        bool signa = dividend > 0;
        bool signb = divisor > 0;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long tmp, num;
        int res = 0;
        while (a >= b) {
            tmp = b;
            num = 1;
            while (tmp <= a) {
                tmp <<= 1;
                num <<= 1;
            }
            tmp >>= 1;
            num >>= 1;
            a -= tmp;
            res += num;
        }
        return signa == signb ? res : -res;
    }
};