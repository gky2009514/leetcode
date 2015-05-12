class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def searchInsert(self, nums, target):
        N = len(nums)
        for i in range(0, N):
            if nums[i] >= target:
                return i
        return N