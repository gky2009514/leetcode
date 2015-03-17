class Solution {
public:
    int atoi(string str) {
        int pos = 0;
        long long res = 0;
        bool neg = false;
        while (pos < str.length() && isspace(str[pos]))
            pos++;
        switch(str[pos]) {
            case '-': neg = true;
            case '+': pos++; break;
            default: break;
        }
        while (pos < str.length() && isdigit(str[pos])) {
            res = res * 10 + str[pos++] - '0';
            if (neg && -res < INT_MIN)
                return INT_MIN;
            if (!neg && res > INT_MAX)
                return INT_MAX;
        }
        return neg ? (int)-res : (int)res;
    }
};