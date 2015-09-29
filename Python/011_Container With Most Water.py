class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        r = len(height) - 1
        if r < 1:
            return 0
        l, ma = 0, 0
        while l < r:
            ma = max(ma, min(height[l], height[r]) * (r - l))
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        return ma