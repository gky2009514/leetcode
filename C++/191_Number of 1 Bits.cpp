class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
        res = (res & 0x0f0f0f0f) + ((res >> 4) & 0x0f0f0f0f);
        res = (res & 0x00ff00ff) + ((res >> 8) & 0x00ff00ff);
        res = (res & 0x0000ffff) + (res >> 16);
        return res;
    }
};