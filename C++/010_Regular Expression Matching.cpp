class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0')
            return check(p);
        if (*p == '\0')
            return false;
        if (*p == '.' || *p == *s) {
            if (*(p + 1) == '*') {
                const char *t = s;
                if (*p == *s) {
                    char c = *s;
                    do {
                        if (isMatch(t, p + 2))
                            return true;
                        t++;
                    } while(*t == c);
                }
                else {
                    do {
                        if (isMatch(t, p + 2))
                            return true;
                        t++;
                    } while(*t != '\0');
                }
                return isMatch(t, p + 2);
            }
            else
                return isMatch(s + 1, p + 1);
        }
        else if (*(p + 1) == '*')
            return isMatch(s, p + 2);
        else
            return false;
    }
private:
    bool check(const char *p) {
        if (*p == '\0')
            return true;
        while (*p != '\0' && *(p + 1) != '\0') {
            if (*(p + 1) != '*')
                return false;
            p += 2;
        }
        return *p == '\0';
    }
};