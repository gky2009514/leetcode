class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if nums is None or len(nums) < 3:
            return []
        nums.sort()
        res, i = [], 0
        while i < len(nums):
            j, k = i + 1, len(nums) - 1
            s = 0 - nums[i]
            while j < k:
                if nums[j] + nums[k] == s:
                    res.append([nums[i], nums[j], nums[k]])
                    while j + 1 < k and nums[j + 1] == nums[j]:
                        j += 1
                    j += 1
                    while j < k - 1 and nums[k - 1] == nums[k]:
                        k -= 1
                    k -= 1
                elif nums[j] + nums[k] < s:
                    while j + 1 < k and nums[j + 1] == nums[j]:
                        j += 1
                    j += 1
                else:
                    while j < k - 1 and nums[k - 1] == nums[k]:
                        k -= 1
                    k -= 1
            while i + 1 < len(nums) and nums[i + 1] == nums[i]:
                i += 1
            i += 1
        return res