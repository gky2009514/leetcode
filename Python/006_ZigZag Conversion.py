class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1:
            return s
        up, l, res = 2 * numRows - 2, len(s), ''
        for i in range(0, l, up):
            res += s[i]
        for i in range(1, numRows - 1):
            for j in range(i, l, up):
                res += s[j]
                if j + up - 2 * i < l:
                    res += s[j + up - 2 * i]
        for i in range(numRows - 1, l, up):
            res += s[i]
        return res
        