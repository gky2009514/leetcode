class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < N; i++) {
            res <<= 1;
            if (n & 1)
                res |= 1;
            n >>= 1;
        }
        return res;
    }
private:
    const int N = 32;
};