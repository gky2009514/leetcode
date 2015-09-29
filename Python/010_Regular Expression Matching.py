
class Solution(object):
    def __init__(self):
        self.dp = []
        self.s, self.p = '', ''
        self.ls, self.lp = 0, 0

    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        self.s, self.p = s, p
        self.ls, self.lp = len(s), len(p)
        self.dp = [[] for _ in range(self.ls)]
        for i in range(self.ls):
            self.dp[i] = [-1 for _ in range(self.lp)]
        return self._match(0, 0) == 1

    def _check(self, y):
        while y < self.lp and y + 1 < self.lp:
            if self.p[y + 1] != '*':
                return False
            y += 2
        return y >= self.lp

    def _match(self, x, y):
        if x >= self.ls:
            return 1 if self._check(y) else 0
        if y >= self.lp or self.dp[x][y] != -1:
            return 0 if y >= self.lp else self.dp[x][y]
        if y + 1 < self.lp and self.p[y + 1] == '*':
            if self.p[y] == '.':
                z = self.ls
            else:
                z = x
                while z < self.ls and self.s[z] == self.p[y]:
                    z += 1
            for i in range(x, z + 1):
                if self._match(i, y + 2) == 1:
                    self.dp[x][y] = 1
                    return self.dp[x][y]
            self.dp[x][y] = 0
        elif self.p[y] == '.' or self.p[y] == self.s[x]:
            self.dp[x][y] = self._match(x + 1, y + 1)
        else:
            self.dp[x][y] = 0
        return self.dp[x][y]