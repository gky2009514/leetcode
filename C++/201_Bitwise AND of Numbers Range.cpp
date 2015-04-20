class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n)
            return m;
        long long res = 0;
        long long mt = m, nt = n;
        for (int i = 1; i <= 31; i++) {
            long long tmp = (long long)1 << i;
            long long mtd = mt / tmp, ntd = nt / tmp;
            long long mtr = mt % tmp;
            if (mtd == ntd && mtr >= (tmp >> 1))
                res |= tmp >> 1;
        }
        return (int)res;
    }
};