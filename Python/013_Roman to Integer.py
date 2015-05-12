class Solution:
    # @param {string} s
    # @return {integer}
    ctod = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    def romanToInt(self, s):
        res = 0
        for i in s:
            res += self._getNum(i)
        pre = 0
        cur = self._getNum(s[0])
        for i in s[1:]:
            pre = cur
            cur = self._getNum(i)
            if pre * 5 == cur or pre * 10 == cur:
                res -= pre << 1
        return res

    def _getNum(self, c):
        return self.ctod.get(c, 0)