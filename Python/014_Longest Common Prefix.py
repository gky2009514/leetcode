class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if strs is None or strs == []:
            return ''
        res = ''
        for i in range(len(strs[0])):
            for j in range(1, len(strs)):
                if len(strs[j]) < i + 1:
                    return res
                if strs[j][i] != strs[0][i]:
                    return res
            res += strs[0][i]
        return res