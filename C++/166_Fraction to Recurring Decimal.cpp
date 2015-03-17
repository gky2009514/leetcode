class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return string("0");
        char *str = new char[N];
        int len = 0;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            str[len++] = '-';
        long long a = abs((long long)numerator);
        long long b = abs((long long)denominator);
        changeNum(str, len, a / b);
        long long reminder = a % b;
        if (reminder)
            str[len++] = '.';
        map<long long, int> mp;
        mp.clear();
        while (reminder) {
            reminder *= 10;
            if (mp.find(reminder) != mp.end()) {
                int pre = mp[reminder];
                for (int i = len; i >= pre; i--)
                    str[i + 1] = str[i];
                str[pre] = '(';
                str[++len] = ')';
                len++;
                break;
            }
            str[len] = reminder / b + '0';
            mp[reminder] = len++;
            reminder %= b;
        }
        str[len] = '\0';
        string s(str);
        delete(str);
        return s;
    }
private:
    const int N = 100000;
    void changeNum(char *str, int &pos, long long num) {
        char tstr[40];
        int tlen = 0;
        do {
            long long tmp = num % 10;
            tstr[tlen++] = tmp + '0';
            num /= 10;
        } while(num);
        for (int i = tlen - 1; i >= 0; i--)
            str[pos++] = tstr[i];
    }
};