class Solution:
    # @param {integer} n
    # @return {integer}
    def totalNQueens(self, n):
        if n == 0 or n == 2 or n == 3:
            return 0
        if n == 1:
            return 1
        self.N = n
        self.col = [False] * n
        self.ltor = [False] * (n << 1)
        self.rtol = [False] * (n << 1)
        self.num = 0
        self._backtrack(0)
        return self.num

    def _backtrack(self, x):
        if x >= self.N:
            self.num += 1
            return
        for i in range(0, self.N):
            if not self.col[i] and not self.ltor[x + i] and not self.rtol[self.N - 1 - i + x]:
                self.col[i] = self.ltor[x + i] = self.rtol[self.N - 1 - i + x] = True
                self._backtrack(x + 1)
                self.col[i] = self.ltor[x + i] = self.rtol[self.N - 1 - i + x] = False