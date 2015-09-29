class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        if n == 0:
            return ''
        ml, res = 0, ''
        for i in range(n):
            if self._isPal(s, i - ml - 1, i):
                res = s[i - ml - 1:i + 1]
                ml += 2
            elif self._isPal(s, i - ml, i):
                res = s[i - ml:i + 1]
                ml += 1
        return res

    def _isPal(self, s, st, ed):
        if st < 0:
            return False
        while st < ed:
            if s[st] != s[ed]:
                return False
            st, ed = st + 1, ed - 1
        return True