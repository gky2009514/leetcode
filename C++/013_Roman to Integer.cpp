class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++)
            result += get_num(s[i]);
        int pre = 0;
        int cur = get_num(s[0]);
        for (int i = 1; i < s.length(); i++) {
            pre = cur;
            cur = get_num(s[i]);
            if (pre * 5 == cur || pre * 10 == cur)
                result -= pre << 1;
        }
        return result;
    }
private:
    int get_num(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};