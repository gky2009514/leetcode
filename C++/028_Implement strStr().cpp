class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int plen = (int)strlen(needle);
        int *lps = new int[plen + 1];
        pre_lps(needle, lps, plen);
        int len = (int)strlen(haystack);
        int i = 0, j = 0;
        while (i < len) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j >= plen)
                return i - j;
            else if (i < len && haystack[i] != needle[j]) {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        delete lps;
        if (j >= plen)
            return i - j;
        return -1;
    }
private:
    void pre_lps(const char *pat, int *&lps, int len) {
        lps[0] = 0;
        int match = 0;
        for (int i = 1; i < len; i++) {
            if (pat[i] == pat[match])
                lps[i] = ++match;
            else {
                while (match && pat[i] != pat[match])
                    match = lps[match - 1];
                if (pat[i] == pat[match])
                    lps[i] = ++match;
                else
                    lps[i] = 0;
            }
        }
    }
};