class Solution(object):
    def __init__(self):
        self.res = []

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self._dfs('', 0, 0, n)
        return self.res

    def _dfs(self, s, l, r, n):
        if l >= n and r >= n:
            self.res.append(s)
            return
        if l < n:
            self._dfs(s + '(', l + 1, r, n)
        if l > r:
            self._dfs(s + ')', l, r + 1, n)