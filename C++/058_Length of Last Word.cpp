class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int last = 0;
        int pos = 0;
        while (s[pos] != '\0') {
            while (isspace(s[pos]))
                pos++;
            if (s[pos] != '\0') {
                last = 1;
                pos++;
            }
            while (s[pos] != '\0' && isalpha(s[pos])) {
                last++;
                pos++;
            }
        }
        return last;
    }
};