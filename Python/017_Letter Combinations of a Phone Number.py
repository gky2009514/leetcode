class Solution(object):
    def __init__(self):
        self.res, self.digits = [], ''
        self.dtol = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        self.digits, self.res = digits, []
        self._dfs(0, '')
        return self.res

    def _dfs(self, pos, stmp):
        if pos >= len(self.digits):
            if len(stmp) > 0:
                self.res.append(stmp)
            return
        d = ord(self.digits[pos]) - ord('0')
        if 1 < d < 10:
            for i in self.dtol[d]:
                self._dfs(pos + 1, stmp + i)
        else:
            self._dfs(pos + 1, stmp)