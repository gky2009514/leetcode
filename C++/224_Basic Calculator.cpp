class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0)
            return 0;
        while (!opr.empty())
            opr.pop();
        while (!ope.empty())
            ope.pop();
        int pos = 0;
        long long num = 0;
        while (pos < s.length()) {
            int r = nextToken(s, pos, num);
            switch (r) {
                case 1:
                case 3:
                case 4: ope.push(s[pos++]); break;
                case 2: calRel(true); pos++; break;
                case 5: opr.push(num); calRel(false); break;
                default: break;
            }
        }
        calRel(false);
        return (int)opr.top();
    }

private:
    stack<long long> opr;
    stack<char> ope;
    int nextToken(const string &s, int &pos, long long &num) {
        while (pos < s.length() && isspace(s[pos]))
            pos++;
        if (pos >= s.length())
            return 0;
        switch (s[pos]) {
            case '(': return 1;
            case ')': return 2;
            case '+': return 3;
            case '-': return 4;
            default: break;
        }
        num = 0;
        while (pos < s.length() && isdigit(s[pos]))
            num = num * 10 + (s[pos++] - '0');
        return 5;
    }
    void calRel(bool match) {
        while (!ope.empty() && ope.top() != '(') {
            long long r = opr.top();
            opr.pop();
            long long l = opr.top();
            opr.pop();
            opr.push(ope.top() == '+' ? l + r : l - r);
            ope.pop();
        }
        if (!ope.empty() && match) {
            ope.pop();
            calRel(false);
        }
    }
};