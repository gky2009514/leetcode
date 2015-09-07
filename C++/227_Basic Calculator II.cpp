class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0)
            return 0;
        int pos = 0;
        while (!num.empty())
            num.pop();
        while (!opr.empty())
            opr.pop();
        while (true) {
            long long nop = getToken(s, pos);
            if (nop == -1) {
                if (pos >= s.length())
                    break;
                if (s[pos] == '+' || s[pos] == '-')
                    opr.push(s[pos++]);
                else {
                    long long l = num.top();
                    num.pop();
                    char op = s[pos++];
                    long long r = getToken(s, pos);
                    num.push(op == '*' ? l * r : l / r);
                }
            }
            else
                num.push(nop);
        }
        long long res = 0;
        while (!opr.empty()) {
            char op = opr.top();
            opr.pop();
            long long r = num.top();
            num.pop();
            res += op == '+' ? r : -r;
        }
        res += num.top();
        return static_cast<int>(res);
    }

private:
    stack<long long> num;
    stack<char> opr;
    long long getToken(const string &s, int &pos) {
        while (pos < s.length() && isspace(s[pos]))
            pos++;
        if (pos >= s.length() || !isdigit(s[pos]))
            return -1;
        long long res = 0;
        while (pos < s.length() && isdigit(s[pos]))
            res = res * 10 + s[pos++] - '0';
        return res;
    }
};