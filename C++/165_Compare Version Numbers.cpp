class Solution {
public:
    int compareVersion(string version1, string version2) {
        int vp1, vp2;
        int prevp1 = -1, prevp2 = -1;
        vp1 = next_point(version1, 0);
        vp2 = next_point(version2, 0);
        do {
            int tmp = check_version(version1, prevp1, vp1, version2, prevp2, vp2);
            if (0 != tmp)
                return tmp > 0 ? 1 : -1;
            prevp1 = vp1, prevp2 = vp2;
            vp1 = next_point(version1, prevp1 + 1);
            vp2 = next_point(version2, prevp2 + 1);
        } while(prevp1 < version1.length() && prevp2 < version2.length());
        if (!check_zero(version1, prevp1 + 1))
            return 1;
        if (!check_zero(version2, prevp2 + 1))
            return -1;
        return 0;
    }
private:
    int next_point(const string &s, int st) {
        for (int i = st; i < s.length(); i++) {
            if ('.' == s[i])
                return i;
        }
        return (int)s.length();
    }
    bool check_zero(const string &s, int st) {
        for (int i = st; i < s.length(); i++) {
            if ('.' != s[i] && '0' != s[i] && !isspace(s[i]))
                return false;
        }
        return true;
    }
    int check_version(const string &s1, int prevp1, int vp1, const string &s2, int prevp2, int vp2) {
        int num1 = 0, num2 = 0;
        for (int i = prevp1 + 1; i < vp1; i++)
            num1 = num1 * 10 + s1[i] - '0';
        for (int i = prevp2 + 1; i < vp2; i++)
            num2 = num2 * 10 + s2[i] - '0';
        return num1 - num2;
    }
};