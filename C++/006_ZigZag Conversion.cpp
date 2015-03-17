class Solution {
public:
    string convert(string s, int nRows) {
        if (1 == nRows)
            return s;
        string res = s;
        int i, j, k, l = (nRows << 1) - 2;
        int len = (int)s.length();
        for (i = j = 0; i < len; i += l)
            res[j++] = s[i];
        for (k = 1; k < nRows - 1; k++) {
            int step = l - (k << 1);
            for (i = k; i < len; i += l) {
                res[j++] = s[i];
                if (i + step < len)
                    res[j++] = s[i + step];
            }
        }
        for (i = nRows - 1; i < len; i += l)
            res[j++] = s[i];
        return res;
    }
};