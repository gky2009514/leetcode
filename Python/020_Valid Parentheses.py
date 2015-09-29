class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stk = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stk.append(i)
            else:
                if len(stk) == 0:
                    return False
                j = stk.pop()
                if i == ')' and j != '(':
                    return False
                if i == ']' and j != '[':
                    return False
                if i == '}' and j != '{':
                    return False
        return len(stk) == 0