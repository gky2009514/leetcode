class Solution:
    # @param {integer[]} prices
    # @return {integer}
    def maxProfit(self, prices):
        if not prices or len(prices) == 1:
            return 0
        N = len(prices)
        i = 0
        res = 0
        while i < N:
            j = i + 1
            while j < N and prices[j] >= prices[j - 1]:
                j += 1
            if j > i + 1:
                res += prices[j - 1] - prices[i]
            i = j
        return res