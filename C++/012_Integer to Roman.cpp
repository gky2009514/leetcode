class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        for (int i = 0; i < 13; i++) {
            while (num >= values[i]) {
                num -= values[i];
                s.append(numerals[i]);
            }
        }
        return s;
    }
private:
    int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string numerals[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
};