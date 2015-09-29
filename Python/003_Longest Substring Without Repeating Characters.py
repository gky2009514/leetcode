class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        appear = dict()
        i, j, l = 0, 0, len(s)
        ma, num = 0, 0
        while j < l:
            if not appear.get(s[j], 0):
                appear[s[j]] = 1
            else:
                while s[i] != s[j]:
                    appear.pop(s[i], None)
                    i, num = i + 1, num - 1
                i, num = i + 1, num - 1
            num, j = num + 1, j + 1
            ma = max(ma, num)
        return ma