class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        res = 0
        for i in nums:
            res ^= i
        return res