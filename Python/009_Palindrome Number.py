class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if x < 10:
            return True
        left = 1
        while left <= x:
            left *= 10
        left /= 10
        right = 1
        while left > right:
            if x // left % 10 != x // right % 10:
                return False
            left, right = left / 10, right * 10
        return True