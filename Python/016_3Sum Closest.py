class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if nums is None or len(nums) < 3:
            return 0
        nums.sort()
        res = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)):
            j, k = i + 1, len(nums) - 1
            while j < k:
                t = nums[i] + nums[j] + nums[k]
                if t == target:
                    return target
                res = t if abs(target - t) < abs(target - res) else res
                if t < target:
                    j += 1
                else:
                    k -= 1
        return res