class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        sums, res = dict(), dict()
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                t = nums[i] + nums[j]
                sums.setdefault(t, [])
                sums[t].append((i, j))
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                t = nums[i] + nums[j]
                lt = sums.get(target - t, [])
                for tp in lt:
                    if i > tp[1]:
                        nlt = (nums[tp[0]], nums[tp[1]], nums[i], nums[j])
                        res[nlt] = 1
        return map(list, res.keys())