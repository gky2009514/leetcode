class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        flag = True if x < 0 else False
        res, x = 0, abs(x)
        while x != 0:
            res = res * 10 + x % 10
            x /= 10
        if flag and -res < -2147483648:
            res = 0
        if not flag and res > 2147483647:
            res = 0
        return -res if flag else res