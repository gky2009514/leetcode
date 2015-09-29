class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.strip()
        l, res = len(str), 0
        if l == 0:
            return 0
        flag = True if str[0] == '-' else False
        i = 1 if str[0] == '-' or str[0] == '+' else 0
        od0, od9 = ord('0'), ord('9')
        while i < l:
            t = ord(str[i])
            if t < od0 or t > od9:
                break
            res = res * 10 + t - od0
            if res > 2147483648:
                break
            i += 1
        if flag and -res < -2147483648:
            res = 2147483648
        if not flag and res > 2147483647:
            res = 2147483647
        return -res if flag else res