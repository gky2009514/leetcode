class Solution:
    # @param {integer} n
    # @return {integer}
    def numTrees(self, n):
        res = 1
        for i in range(2, n + 1):
            res = res * ((i << 2) - 2) / (i + 1)
        return res