class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        res = 0
        for i in range(0, 32):
            if n & (1 << i) != 0:
                res += 1
        return res