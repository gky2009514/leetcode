class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ht = dict()
        for i in range(len(nums)):
            ht[nums[i]] = i + 1
        for i in range(len(nums)):
            lt = target - nums[i]
            if ht.get(lt, None) is not None:
                if ht[lt] == i + 1:
                    continue
                return [min(i + 1, ht[lt]), max(i + 1, ht[lt])]