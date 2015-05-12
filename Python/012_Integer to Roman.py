class Solution:
    # @param {integer} num
    # @return {string}
    dtos = {1000: "M", 900: "CM", 500: "D", 400: "CD", 100: "C", 90: "XC",
            50: "L", 40: "XL", 10: "X", 9: "IX", 5: "V", 4: "IV", 1: "I"}
    def intToRoman(self, num):
        tarr = sorted(self.dtos, reverse=True)
        res = ""
        for i in range(len(self.dtos)):
            while num >= tarr[i]:
                num -= tarr[i]
                res += self.dtos[tarr[i]]
        return res